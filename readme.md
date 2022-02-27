## Setup environment

Clone repository with SSH for working with `ghp-import` (it's easier).
Install requiremens `pip install pelican markdown ghp-import`.

## Write new article

1. Write article with Notion. 
2. Export in Markdown. It will include links to static images.
3. Navigate to blog repository.
4. `git checkout website`
    1. At this point, it’s a good idea to run the development server to check everything is running smoothly.
5. Create new folder in content/blog with the scheme `000X_simple_title`, where `X` is the monotonically increasing integer identifying the article.
6. Copy the exported files from Notion to this new folder.
7. Fix the header fields in the `.md` file.
    
    ```bash
    Title: Dinoboy western
    Date: 2021-01-28
    tags: zen, motorcycles
    ```
    
8. Fix image links.
    1. Prepend `{attach}` before the path of every image in the article.
9. Fix links to other articles
    1. Use paths relative to the .md of the article, e.g. if the article lives in the folder `content/blog/0002_dinoboy_western`, it can reference another article like this `[link text]({filename}../0001_previous_article/the_alienstones.md)`.
10. Add the following to the end of each article.
    
    What do you think? How would you improve on this? Drop me a message at [blog@diogoaos.com](mailto:blog@diogoaos.com).
    

## Development server

`pelican -r -l content -o output -s pelicanconf.py -p 5555`

## Publish

```
pelican content -o output -s publishconf.py
ghp-import output/ -b master -p -c www.diogoaos.com

```
