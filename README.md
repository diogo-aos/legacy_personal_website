Clone repository with SSH for working with `ghp-import` (it's easier).
Install requiremens `pip install pelican markdown ghp-import`.

# Development
```pelican -r -l content -o output -s pelicanconf.py -p 5555```

# Publish
```
pelican content -o output -s publishconf.py
ghp-import output/ -b master -p -c www.diogoaos.com
```
