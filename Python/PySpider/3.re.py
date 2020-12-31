import re
s1 = '<a rel="noreferrer" href="/p/7170699526" title="这是什么梗，来个老哥解释一下" target="_blank" class="j_th_tit ">这是什么梗，来个老哥解释一下</a>'
s2 = '<a rel="noreferrer" href="/p/7175292280" title="论巨人里那个角色的死最让你心痛 我先来 放图" target="_blank" class="j_th_tit ">论巨人里那个角色的死最让你心痛 我先来 放图</a>'

pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".*?".*?>(.+?)</a>.*?')
print(pattern.findall(s1))

s1 = '<img class="BDE_Image" src="http://tiebapic.baidu.com/forum/w%3D580/sign=7b5aee8fc02a60595210e1121835342d/62c04c09c93d70cf1192a84befdcd100bba12b0d.jpg" size="500097" changedsize="true" width="560" height="431">'
s2 = '<img class="BDE_Image" src="http://tiebapic.baidu.com/forum/w%3D580/sign=fdbf22b821d3d539c13d0fcb0a86e927/6f756c10b912c8fcf79bf48beb039245d788210d.jpg" size="686147" changedsize="true" width="560" height="635">'

pattern = re.compile(r'<img.*?src="(.*?)" .*?>')
print(pattern.findall(s1))

s3 = '<a href="/p/7170699526?pn=2">下一页</a>'

pattern = re.compile(r'<a href="(/p/.*?)>.*?下一页.*?</a>.*?')

print(pattern.findall(s3))
