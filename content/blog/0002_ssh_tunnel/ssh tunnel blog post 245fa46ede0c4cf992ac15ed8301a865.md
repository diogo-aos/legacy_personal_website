Title: Bypass firewalls and routers with reverse tunnels
Date: 2021-03-27
tags: ssh, tunnel

If you regularly work with remote, screenless machines, you probably regularly work with SSH too. SSH is great to access a machine, but what if it sits behind a router or firewall and you can't change the rules? That's what this is article is about: reverse tunnels!

# The typical SSH connection

The simplest scenario is a direct connection between host A and B. Let's say A wants to SSH into B. You simply type `ssh username@B` in a terminal in host A.

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled.png]({static}/blog/ssh_tunnel_blog_post/Untitled.png)

Simple enough. This is just a normal SSH connection. Let's get into tunnels.

# The forward tunnel

You use tunnels when you want to forward connections in specific ports. Let's say A wants to access a Jupyter Notebook server running on host B, on port 8888, and we want to be able to access it in host A as if it were running locally, on the same port. We can use a tunnel, that will forward all connections in port 8888 of host A to port 8888 of host B.

If you go to a browser in host A and access `localhost:8888`, sure enough, you'd get the Jupyter Notebook page (that is served on host B).

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%201.png]({static}/blog/ssh_tunnel_blog_post/Untitled%201.png)

But what if host B sits behind a router or firewall? Well, no problem, you just need to create a port forwarding rule that ensures that a connection to routerB will be forwarded to the SSH port of host B. Let's say port 22 (default SSH port) of routerB is being forwarded to port 22 of host B.

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%202.png]({static}/blog/ssh_tunnel_blog_post/Untitled%202.png)

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%203.png]({static}/blog/ssh_tunnel_blog_post/Untitled%203.png)

If B sits behind a router, you just need to make sure there is a port forwarding rule from port 22 of routerB to port 22 of B. But what if you can't configure the router or firewall?

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%204.png]({static}/blog/ssh_tunnel_blog_post/Untitled%204.png)

# The reverse tunnel

That's where reverse tunnels enter the picture. You can't access host B with a SSH connection, because B is fenced. There is no way in. But, if you have direct access to it, if you can directly configure it (e.g. manually), then you can still make the connection work by using a **reverse tunnel**. We still have the same scenario, that is, we want A to be able to access, locally, the Jupyter Notebook running in host B (this could be any service, really).

Before, we used the `-L` option, which forwarded local connection on port 8888 of A to port 8888 of B. We still want to do that, but now the SSH connection will start from host B. If we used `-L` again, we'd be forwarding connections on port 8888 of B to port 8888 of A, exactly the opposite of what we want. We need to reverse this, by using `-R` option instead. It works exactly as `-L`, but in a different direction. 

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%205.png]({static}/blog/ssh_tunnel_blog_post/Untitled%205.png)

Note that the SSH connection is initiated from B to A, but the forwarded connections inside the tunnel are from A to B. Notice how the purple arrow (initial SSH connection) is now going leftwards, but the blue arrow (the forwarding tunnel) is still going towards the right.

With this, you're done. You can, once again, access the Jupyter Notebook in port 8888 of localhost in host A and it will be served pages from host B (port 8888).

# SSH into a firewalled host with a reverse tunnel

Let's forget about Jupyter Notebooks for now. The more common case is just making a SSH connection into a firewalled host. Using a reverse tunnel, it's easy. Let's break it apart:

- B initiates a SSH connection to A: `ssh anotherUser@A`
- This is the base command. We then add the reverse tunnel on top of that, to forward connection on port X of A (let's give it a number, say 12345) to port 22 of B. B actually executes `ssh -R 12345:[localhost](http://localhost):22 anotherUser@A`. Now A can access port 22 of localhost of host B if it makes connections on port 12345 on localhost of A (the diagram below clarafies this).
- Then you can just type `ssh -p 12345 username@localhost` to have an interactive SSH session in a terminal in host A. This will initiate a SSH connection in port 12345 of localhost, which is forwarded, by the reverse tunnel, to port 22 of host B, creating the desired connection.

With this inceptionesque scenario, we have a SSH connection (blue arrow, initiated by A) inside another SSH connection (big pink arrow, initiated by B).

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%206.png]({static}/blog/ssh_tunnel_blog_post/Untitled%206.png)

We've now covered the typical ways both normal and reverse tunnels are used. You can use this knowledge to have communication rolling even when you have to deal with pesky firewalls and inaccessible routers.

A convoluted, but common setup, is having a router sitting between A and the internet (check the diagram below). Let's say we have a routerA that forwards port 6789 to port 22 (SSH's default port) of host A. The goal is still the same: have host A access the firewalled host B. This is not really that much more complex, but we have to "divide and conquer" the problem, or layer it:

- Host B must create a SSH connection to host A. This was done with `ssh anotherUser@A`.
- But now, A is behind routerA and port 6789 of routerA is forwarding to port 22 of A, so we have to specify that port in the original SSH connection: `ssh anotherUser@routerA -p 6789`. Since port 6789 of routerA is forwarding to port 22 of A, we get our connection.
- B must create a reverse tunnel. This part we already covered: `ssh -R 12345:localhost:22 anotherUser@routerA -p 6789`.
- Finally, host A connects to host B as before, `ssh -p 12345 username@localhost`

![ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/Untitled%207.png]({static}/blog/ssh_tunnel_blog_post/Untitled%207.png)

What if we also can't configure routerA? That means no port forwarding is in place and neither A nor B can receive connections! The only way out of that one is to make a blood sacrifice. Chickens 🐔 usually do it. Goats 🐐 if you want to get fancy. Or, perhaps, with a third host, with tunnels initiated in A and B... That's homework material!

**Sources**

[https://unix.stackexchange.com/questions/46235/how-does-reverse-ssh-tunneling-work](https://unix.stackexchange.com/questions/46235/how-does-reverse-ssh-tunneling-work)

---

You want to SSH into a machine that sits behind a firewall. You can physically access the machine, but you can't configure the firewall, which means there is no port forwarding to the firewalled host.

[reverse_tunnel.pptx](https://drive.google.com/file/d/1Aepwzvv6DC4dmMFgYTE-rEFOKj6Fy4Jz/view?usp=drivesdk)

[reverse_tunnel.odp](ssh%20tunnel%20blog%20post%20245fa46ede0c4cf992ac15ed8301a865/reverse_tunnel.odp)

```bash
-R [bind_address:]port:host:hostport
-R [bind_address:]port:local_socket
-R remote_socket:host:hostport
-R remote_socket:local_socket
-R [bind_address:]port
Specifies that connections to the given TCP port or Unix socket on the remote (server) host are to be forwarded to the local side.
This works by allocating a socket to listen to either a TCP port or to a Unix socket on the remote side. Whenever a connection is
made to this port or Unix socket, the connection is forwarded over the secure channel, and a connection is made from the local ma‐
chine to either an explicit destination specified by host port hostport, or local_socket, or, if no explicit destination was speci‐
fied, ssh will act as a SOCKS 4/5 proxy and forward connections to the destinations requested by the remote SOCKS client.
Port forwardings can also be specified in the configuration file. Privileged ports can be forwarded only when logging in as root on
the remote machine. IPv6 addresses can be specified by enclosing the address in square brackets.
By default, TCP listening sockets on the server will be bound to the loopback interface only. This may be overridden by specifying
a bind_address. An empty bind_address, or the address ‘*’, indicates that the remote socket should listen on all interfaces. Spec‐
ifying a remote bind_address will only succeed if the server's GatewayPorts option is enabled (see sshd_config(5)).
If the port argument is ‘0’, the listen port will be dynamically allocated on the server and reported to the client at run time.
When used together with -O forward the allocated port will be printed to the standard output.
```

```bash
-L [bind_address:]port:host:hostport
     -L [bind_address:]port:remote_socket
     -L local_socket:host:hostport
     -L local_socket:remote_socket
             Specifies that connections to the given TCP port or Unix socket on the local (client) host are to be forwarded to the given host and
             port, or Unix socket, on the remote side.  This works by allocating a socket to listen to either a TCP port on the local side, op‐
             tionally bound to the specified bind_address, or to a Unix socket.  Whenever a connection is made to the local port or socket, the
             connection is forwarded over the secure channel, and a connection is made to either host port hostport, or the Unix socket
             remote_socket, from the remote machine.

             Port forwardings can also be specified in the configuration file.  Only the superuser can forward privileged ports.  IPv6 addresses
             can be specified by enclosing the address in square brackets.

             By default, the local port is bound in accordance with the GatewayPorts setting.  However, an explicit bind_address may be used to
             bind the connection to a specific address.  The bind_address of “localhost” indicates that the listening port be bound for local use
             only, while an empty address or ‘*’ indicates that the port should be available from all interfaces.
```
