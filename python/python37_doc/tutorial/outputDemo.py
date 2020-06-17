def out_demo():
    import reprlib
    print(reprlib.repr(set('supercalifragilisticexpialidocious')))

    import pprint
    t = [[[['black', 'cyan'], 'white', ['green', 'red']], [['magenta', 'yellow'], 'blue']]]
    pprint.pprint(t)

    import textwrap
    doc = """The wrap() method is just like fill() except that it returns
a list of strings instead of one big string with newlines to separate
the wrapped lines."""
    print(textwrap.fill(doc, width=40))

    from string import Template
    t = Template('${village}folk send $$10 to $cause.')
    print(t.substitute(village='Nottingham', cause='the ditch fund'))

    t = Template('Return the $item to $owner.')
    d = dict(item='unladen swallow')
    print(t.safe_substitute(d))


if __name__ == '__main__':
    out_demo()
