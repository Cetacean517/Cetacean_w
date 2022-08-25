# 数学表达式
# 语法：
# plt.title('r$\alpha > \beta$')

# 绘制表达式 r'$\alpha_i> \beta_i$'
import numpy as np
import matplotlib.pyplot as plt

t = np.arange(0.0, 2.0, 0.01)
s = np.sin(2 * np.pi * t)
# 绘制函数图像
plt.plot(t, s)
# 设置标题
plt.title(r'$\alpha_i> \beta_i$', fontsize=20)
# 设置数学表达式
plt.text(0.6, 0.6, r'$\mathcal{A}\mathrm{sin}(2 \omega t)$', fontsize=20)
# 设置数学表达式
plt.text(0.1, -0.5, r'$\sqrt{2}$', fontsize=10)
plt.xlabel('time (s)')
plt.ylabel('volts (mV)')
plt.show()
