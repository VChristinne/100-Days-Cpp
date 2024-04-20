# conf.py
import os
import sys
sys.path.insert(0, os.path.abspath('..'))

project = 'Zed'
author = 'Christinne'

extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.doctest',
    'sphinx.ext.intersphinx',
    'sphinx.ext.todo',
    'sphinx.ext.coverage',
    'sphinx.ext.mathjax',
    'sphinx.ext.viewcode',
]

templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'

language = None
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

pygments_style = 'sphinx'
todo_include_todos = True

html_theme = 'classic'
html_static_path = ['_static']
htmlhelp_basename = 'Zeddoc'