import mongoengine as me
from datetime import datetime


class Page(me.DynamicDocument):
    title = me.StringField(max_length=200, required=True)
    date = me.ComplexDateTimeField(default=datetime.now)
    meta = {'collection': 'test'}


if __name__ == '__main__':
    me.connect('test')
    page = Page(title='Using MongoEngine')
    page.tags = ['mongodb', 'mongoengine']
    page.save()
    print(Page.objects(tags='mongoengine').count())
    print(page.id)
    page1 = Page(title='Using')
    page1.save()
    print(page.to_json())
    # for each in Page.objects:
    #     print(each)