# _Filter & Listener_

_Filter: When accessing the resource of the servers, the filter can intercept the request to complete some special functions_



## _Function of filter_

_It is generally used to complete the operation of passing_

_such as: validate logon, Unified coding processing and sensitive character filtering_



_The most chief feature is universal_



## _Quick start_

_define a class and implement the interface filter_



_override the method_

>_init_
>
> 
>
>___doFilter___
>
>_Clearance_
>
>```
>filterChain.doFilter(servletRequest, servletResponse)
>```
>



_Configure interception path_

>_web.xml_
>
>_@WebFilter("/*")_
>
>_Filtering occurs when accessing any resource of the servers_
>
>_annotation_



## _details_z

### _web.xml Configuration_

similar to servlet



### _filter lifecycle_

init

doFilter

destory



_similar to servlet_



### _Configuration_

#### _Configuration path_

>/index.jsp
>
>only access index.jsp
>
>/user/*
>
>only access all the files in the directory
>
>*.jsp
>
>only access all files with jsp suffix
>
>/*
>
>access all files



#### _Configuration mode_

>_web.xml_
>
>_annotation_
>
>_dispatcherTypes = {DispatcherType.$, ...}_
>
>REQUEST  default value, browser requests resources directly
>
>FORWARD  forward access resource
>
>INCLUDE  include access resource
>
>ERROR    error jump resource
>
>ASYNC	async access resource

### _Execution_



### _filter chain_

_if there are two filters, filter1 and filters2_

_the execute order is filter1, filter2, resource, 2, 1_



_order_

annotation configuration

compare in dictionary order, the dictionary order is small in the front



web.xml

\<filter-mapping> is upper in the front 



## _Listener_

event listener.



ServletContextListener 监听serlvetContext对象的监听和销毁
