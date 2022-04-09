# Maven

Maven常用命令

mvn ~

compile 将java文件编译为.class文件置于target目录内

clean 删除target目录

package 将项目先编译， 然后压缩为war包

install 将项目安装到本地仓库里面去





Maven生命周期



默认生命周期: 编译 测试 打包 安装   

执行后面的操作会先执行前面的所有操作



坐标: 被maven管理的资源的唯一标识

groupId 组织名称

artifactId 



pom.xml

\<packaging>

​	jar(java项目， 默认值)

​	war(web项目)

​	pom

</...>



添加插件

\<build>\</build>