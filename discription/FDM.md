平面上の点(x,y)の関数u(x,y)に対するラプラス演算子 $ \Delta $ は、
$$ \Delta u= \frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2}$$
で定義される。$N\times N$の正方形の領域D内で、ラプラス方程式
$$ \Delta u = 0 $$
を満たし、かつDの境界 $ \Gamma $上でu(x,y)が指定された値を取るように関数u(x,y)を定める。

$\frac{\partial^2 u}{\partial x^2}$に対して差分近似を求めると
$$ \frac{\partial^2 f}{\partial x^2} =
\lim_{\Delta x \to 0} \frac{\Delta u'}{\Delta x} =
 \lim_{\Delta x \to 0} \frac{u'(x+\Delta x) - u'(x)}{\Delta x}$$
 刻み幅をhとして,離散化された正方形内の点を$(i,j)$で表せば
 $$ \frac{\partial^2 f}{\partial x^2}  = \frac{(u_{i+1,j }-u_{i,j})/h - (u_{i,j }-u_{i-1,j})/h}{h} \\
 =\frac{u_{i+1,j} - 2u_{i,j} + u_{i-1,j}}{h^2}$$
 $\frac{\partial^2 u}{\partial y^2}$についても同様に

 $$ \frac{\partial^2 u}{\partial y^2}=\frac{u_{i,j+1} - 2u_{i,j} + u_{i,j-1}}{h^2} $$

よって,ラプラス方程式は差分近似では以下のように置き換えることができる
$$u_{i,j} = \frac {u_{i+1,j} +u_{i-1,j} +u_{i,j+1} +u_{i,j-1} }{4}$$
なお,境界条件は
$$u(x,0) =0\,\,(0\le x\le N), u(0,y)=0\,\,(0\le y\le N),\\
u(x,N) =0 \,\,(0\le x\le N), u(N,y)=0 \,\,(0\le y\le N)$$

とした

参考文献
森口繁一 『数値計算工学』 岩波書店
平瀬創也 『C#で学ぶ偏微分方程式の数値解法』 東京電機大学出版局
