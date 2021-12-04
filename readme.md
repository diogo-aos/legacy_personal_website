dev command

## dev
pelican -r -l content -o output -s pelicanconf.py -p 5555

## publish
pelican content -o output -s publishconf.py
ghp-import output/ -b master -p -c www.diogoaos.com

