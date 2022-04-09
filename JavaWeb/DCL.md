# DCL

DCL是用于管理用户和授权的操作。



## 查询用户

切换到mysql数据库

use mysql;

查询user表

select * from user;



## 创建用户

create user '用户名'@'主机名' identified by '密码';



## 删除用户

drop user '用户名'@'主机名'



## 修改密码

update user set password = password('新密码') where user = '用户名' 

set password for 'root'@'localhost' = password('新密码')

