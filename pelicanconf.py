AUTHOR = 'Diogo Silva'
SITENAME = 'Diogo Silva'

#SITEURL = 'http://localhost'

TIMEZONE = 'Europe/Lisbon'

DEFAULT_LANG = 'en'

# Feed generation is usually not desired when developing
FEED_ALL_ATOM = None
CATEGORY_FEED_ATOM = None
TRANSLATION_FEED_ATOM = None
AUTHOR_FEED_ATOM = None
AUTHOR_FEED_RSS = None

# Blogroll
LINKS = ()

# Social widget
SOCIAL = (('Github', 'https://github.com/diogo-aos'),
         ('LinkedIn', 'https://www.linkedin.com/in/diogoaos'),)

DEFAULT_PAGINATION = False

# Uncomment following line if you want document-relative URLs when developing
#RELATIVE_URLS = True

PATH = 'content'
ARTICLE_PATHS = ['blog']
STATIC_PATHS = ['blog']

THEME = 'aboutwilson'

INDEX_SAVE_AS = "index.html"
ARCHIVES_SAVE_AS = 'blog/index.html'
ARTICLE_URL = 'blog/{slug}/'
ARTICLE_SAVE_AS = 'blog/{slug}/index.html'
ARTICLE_ORDER_BY = 'reversed-date'
DISPLAY_CATEGORIES_ON_MENU = False
DISPLAY_PAGES_ON_MENU = False


#SITESUBTITLE = 'Computer Engineer, Climber'
#SITESUBTITLE = 'Air Force Captain, Computer Engineer, Climber'

MENUITEMS = (
#  ('Home','/'),
#  ('About','/about/'),
#  ('Contact','/contact/'),
  ('Blog','/blog/'),
)
