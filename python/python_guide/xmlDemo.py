import xmltodict

# xmltodict also lets you roundtrip back to XML with the unparse function,
# has a streaming mode suitable for handling
# files that don’t fit in memory and supports namespaces
if __name__ == '__main__':
    with open('test.xml') as fd:
        doc = xmltodict.parse(fd.read())
        print(doc['mydocument']['@has'])  # == u'an attribute'
        print(doc['mydocument']['and']['many'])  # == [u'elements', u'more elements']
        print(doc['mydocument']['plus']['@a'])  # == u'complex'
        print(doc['mydocument']['plus']['#text'])  # == u'element as well
