#基于轮廓识别的新型二维码   
   
   
##使用方法    
下载并且用visual studio 2015加载后，调整为X64即可    
    
需要opencv 3.2的支持    
http://pan.baidu.com/s/1nvFGWJ3      
下载后将opencv目录放在d盘下     

##生成范例   
四个角上的识别标记可以被替换为其他图形，只要该图形的最深层次大于等于6即可
<img src="https://github.com/Borelset/spectrum/blob/master/code.jpg" width = "300" height = "300" />
    

##感谢    
感谢mersinvald的Reed-Solomon项目提供的里德所罗门算法的实现。        
本项目中的poly.hpp / gf.hpp / rs.hpp 来自       
https://github.com/mersinvald/Reed-Solomon
