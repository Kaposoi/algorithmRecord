# css文字属性

​																									---文明的沉淀。

---

font-family: 字体。

>font-family: 'Microsoft YaHei' 单引号包含适用于多单词组成的一个字体。一单词的字体可以不加引号
>
>font-family: 'Times New Roman', Times, Aries... 若第一个字体找不到则后面依次寻找字体。

font-size: 文字大小。

>font-size: 30px
>
>默认是16px（谷歌）
>
>不同浏览器的默认大小可能不同，因此尽量给出一个确定的字。

font-weight: 文字的粗细

>bold 字体加粗
>
>bolder 特粗
>
>lighter 特细
>
>可以给数字。
>
>font-weight: 700 无单位。
>
>更提倡使用数字。
>
>700 == bold 400 == normal

font-style 文字的倾斜

>italic 斜体。
>
>normal 默认，正常。

字体的复合属性。

font: style weight size family依次写。

>size和family属性必须存在，否则font无用。