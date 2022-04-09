# 常用linux命令

小技巧

>ctrl + shift + = 放大终端字体的显示。
>
>ctrl + - 缩小终端字体的显示。

常用命令

>ls -> list 查看当前文件夹下的内容
>
>pwd -> print work directory 查看当前所在文件夹
>
>cd (目录名) -> change directory 切换文件夹
>
>touch [文件名] -> touch 如果文件夹不存在，新建文件
>
>mkdir [目录名] -> make directory 创建目录
>
>rm [文件名] -> remove 删除指定文件名
>
>clear -> clear 清屏

终端命令格式

>command [-options] [parameter] // 命令名， 选项， 传递给命令的参数。

查询命令帮助信息

>command --help
>
>man command

拓展

ls

>ls -a 查看所有文件（主要是包含隐藏文件）
>
>ls -l 以列表方式显示文件所有信息
>
>ls -h 配合-l以人性化的方式显示文件大小
>
>

rm

>rm -r 递归地删除文件（目录必须用这个）
>
>rm -f 强制删除，忽略任何提示。

touch

>touch .123.txt(以.开头的文件是隐藏文件。) 在终端中一个.表示当前目录，..表示上级目录
>
>如果文件不存在，创建。否则修改末次修改日期

cd

>cd 
>
>cd ~ 同上，返回自己的home目录。
>
>cd .. 返回上级目录
>
>cd . 当前目录
>
>cd - 在最近两次工作目录间来回切换。
>
>绝对路径: 最前面是/或者~
>
>相对路径: 最前面没有/或者~

mkdir

>mkdir -p 递归的创建多个目录
>
>mkdir -p a/b/c/d/e