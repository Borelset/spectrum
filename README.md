基于轮廓识别的新型二维码   
============================== 
   
使用方法
----------------------------
如果仅仅是想使用生成的程序，那么下载spectrum文件夹即可。          
       
完整代码需要下载整个项目，下载后并且用qt加载。     
编译需要opencv 3.2的支持         

生成范例
-----------------------------------
程序中有已经制作好的三个模板，任选其一即可，当然也可以自制模板。                          

四个角上的识别标记可以被替换为其他图形，只要该图形的最深层次大于等于6。      

<img src="https://github.com/Borelset/spectrum/blob/master/code.jpg" width = "300" height = "300" />     
    

感谢  
-------------------------
感谢mersinvald的Reed-Solomon项目提供的里德所罗门算法的实现。        
本项目中的poly.hpp / gf.hpp / rs.hpp 来自       
https://github.com/mersinvald/Reed-Solomon
