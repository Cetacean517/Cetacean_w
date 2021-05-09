# Pygame
## 1. Pygame最小开发框架
### 引入pygame和sys
- sys是Python的标准库
- sys提供Python运行时环境变量的操控
- sys.exit()用于退出：结束游戏并退出

### 初始化init()及设置
对Pygame内部各功能模块进行初始化创建及变量设置，默认调用

```python
pygame.init()
screen = pygame.display.set_mode((600,400))
pygame.display.set_caption("Python游戏之旅")
```
### 获取事件并逐类响应
### 刷新屏幕