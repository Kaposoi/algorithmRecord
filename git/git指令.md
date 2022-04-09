# git指令

设置用户名

git config --global user.name 用户名

设置邮箱

git config --global user.email 邮箱



以上两个指令， 不输入用户名或者是邮箱就是查看



基础操作命令

git工作目录下对于文件的修改(增加， 删除， 更新), 会存在几个状态， 这些修改的状态会随着我们执行git的命令而发生变化

![status](F:\E盘\编程学习\git\status.png)

git status

查看文件状态



git add 文件名|通配符



git commit -m "注释"

git commit -a 提交所有tracked文件， 此时可以不使用git add



git log 获得提交日志

options:

--all 显示所有分支

--pretty=oneline 显示为一行

--abbrev-commit 输出更简短

--graph 以图的形式显示

-patch 显示提交引入的差异

-x 显示最近的x条提交



git reset --hard commitID

ID可以用git logE查看

版本回退



git reflog 查看提交记录



添加文件至忽略列表

在工作目录下创建一个.gitignore的文件， 列出要忽略的文件模式

>*.a
>
>!lib.a
>
>/TODO
>
>build/
>
>doc/*.txt
>
>doc/**/*.pdf





移除文件

git rm 文件

这样只能删除非暂存区的文件

git rm -f 文件

强制删除



解除跟踪

git rm --cached 文件



重命名

git mv 之前的名字 之后的名字



提交覆盖

git commit --amend

暂存区的文件会覆盖上次提交的文件， 不会保留上次提交的记录。



取消暂存

git reset HEAD \<file>...



撤销修改

git checkout -- \<file>