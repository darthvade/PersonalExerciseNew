#!/usr/bin/python

from goose import Goose
from goose.text import StopWordsChinese

url = 'http://www.baidu.com'

g = Goose({'stopwords_class':StopWordsChinese})

article = g.extract(url = url)

print article.cleaned_text[:150]

