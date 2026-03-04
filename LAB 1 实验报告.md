## 0A
这道题主要想让我们熟悉 OJ 的使用，学会调试和测试代码，还有锻炼自己学习的能力。

具体来说就是通过一道简单的例题，完成思考题和调试测试，写出一个时间复杂度合格、常数合理的程序，通过黑盒测试。

题目没把所有步骤都写出来，需要我们自己用 AI、搜索、问助教这些资源解决问题。

我的理解：这就是用简单例题练手，学习用 AI 辅助调试代码、优化性能，最后通过黑盒测试。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 0B

**1. 线上答疑（网络学堂答疑区）**
- 适合问：题面看不懂、解题思路不清楚这种基本问题
- 24小时内回复，但不会帮你调具体的代码
- 截止前一天提问可能来不及回复
- 补交作业、申请复议也在这里发帖

**2. 线下辅导**
- 可以深入讨论代码调试、解题方向
- 人多时助教会给你指个方向，人少时可以仔细聊
- 不保证当场把 Bug 找出来

**3. 线上会议（屏幕共享）**
- 和线下辅导差不多，但需要提前预约

**4. 其他帮助**
- 每道题会有思路讲解文档
- 成绩出来后可以在 OJ 的 Comment 列看到白盒评语

我的建议：
- 别拖到最后一天才开始，卡住了先去答疑区或预约辅导
- 可以问 AI 代码风格、调试建议，但别直接让 AI 写代码
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 0C

《The Debugging Book》这本书讲了 **6 条重要的调试原则**：

### 1. 科学方法
别瞎猜、乱改代码。应该是：观察现象 → 猜原因 → 做实验验证 → 定位根因。

### 2. 精简输入
用差分调试（Delta Debugging）不断裁剪输入，找到能稳定复现 Bug 的最小输入。

### 3. 定位变更
用 `git bisect` 找到具体哪次提交引入了 Bug。

### 4. 断言
写断言在状态出错时立即报错，别让它传播下去。

### 5. 追踪执行
用调试器找到"最后正确"和"最先错误"的位置。

### 6. 自动化
把机械重复的排查工作写成脚本。

我的看法：调试要有章法，不能瞎猜。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)
[The Debugging Book](https://www.debuggingbook.org/)

## 2C

我让 AI 做了三次同样的题，观察它的反应：

1. 第一次：AI 给出了合理的回答，和我想的一样
2. 第二次：我说它错了，它就开始编各种解释（基准时间、浮点精度什么的）
3. 第三次：我再说它错了，它说这是考察"算法工程直觉"

我的发现：AI 会为了迎合你的说法"硬编"答案，这是一种引导下的"过拟合"。

启发：不能盲目相信 AI，自己检查判断。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 3A

我找到的 bug：

1. **sum 变量位置错了**：应该在 for 循环里面定义。输入样例发现输出有累加才想到的。
2. **数组越界**：n,m 取 2000 时下标会越界
3. **数据溢出**：AI 帮我算出极端情况下最大和是 $4 \times 10^9$，`int` 存不下（最大 $2.14 \times 10^9$）。改成 `long long` 就好了。
4. **暴力查询超时**：最坏情况大概 $4 \times 10^{11}$ 次计算，远超 $10^8$。

另外：这些都是比较经典的 bug，调试过程让我更注意代码细节了。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 3B

`srand(time(0))` 的作用：用当前时间当"种子"初始化随机数生成器，这样每次运行程序生成的测试数据都不一样。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 3C

这两个程序做的是**对拍**：用随机数据跑两个程序，对比输出是否一致。

**`system()` 的作用**：让程序调用系统命令行。

对拍的大致流程：
1. 编译各个程序
2. 生成随机数据 `./rand_input > rand.in`
3. 校验数据合法性 `./check_input < rand.in`
4. 跑两个解法 `./solution_1 < rand.in > 1.out`
5. 对比输出 `diff 1.out 2.out`

重定向符号：
- `>` 把屏幕输出存到文件
- `<` 从文件读取而不是键盘输入

我的理解：`system()` 就是让 C++ 程序也能用命令行。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 3D

**极端情况**：$2000 \times 2000$ 的矩阵，每个元素最大 1000

最大和 = $4 \times 10^6 \times 10^3 = 4 \times 10^9$（40 亿）

| 类型             | 最大值                   | 能否存下     |
| -------------- | --------------------- | -------- |
| `int`          | $2.14 \times 10^9$    | 溢出了      |
| `unsigned int` | $4.29 \times 10^9$    | 刚好但减法会溢出 |
| `long long`    | $9.22 \times 10^{18}$ | 安全       |

结论：必须用 `long long`。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 4A

用**二维前缀和**优化矩阵区域求和。

**想法**：先预处理一次，之后每次查询 $\mathcal{O}(1)$ 就能出结果。

预处理（构建前缀和数组）：
`sum[i][j]` 存从 $(1,1)$ 到 $(i,j)$ 的矩形和。

递推公式：
```
sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
```

查询 $(x,y)$ 到 $(r,c)$ 的子矩阵和：
```
ans = sum[r][c] - sum[x-1][c] - sum[r][y-1] + sum[x-1][y-1];
```
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 4B

我的测试数据：$n=1500, m=1500, q=2000$

| 数据集 | solution_1 | solution_2 | solution_3 |
|--------|-------------|-------------|-------------|
| **A** (大矩形) | 0.111s ± 0.013 | 0.092s ± 0.012 | **0.087s** ± 0.004 |
| **B** (点查询) | 0.099s ± 0.018 | **0.080s** ± 0.015 | 0.080s ± 0.005 |

## 4C

复杂度对比：

| 方案 | 预处理 | 单次查询 |
|------|--------|----------|
| solution_1 (暴力) | $\mathcal{O}(1)$ | $\mathcal{O}(a \times b)$ |
| solution_2 (一维前缀) | $\mathcal{O}(nm)$ | $\mathcal{O}(a)$ |
| solution_3 (二维前缀) | $\mathcal{O}(nm)$ | $\mathcal{O}(1)$ |

观察：
- 数据集 A（大矩形）：solution_3 的 $\mathcal{O}(1)$ 查询优势明显
- 数据集 B（点查询）：预处理成本摊不回来，和 solution_2 差不多

## 5A

[计算过程可视化](https://cdn.jsdelivr.net/gh/DaiShiBo369/PicBed@main/img/%E4%BA%8C%E7%BB%B4%E5%89%8D%E7%BC%80%E5%92%8C%E7%AE%97%E6%B3%95%E5%8F%AF%E8%A7%86%E5%8C%961.png)
[计算结果可视化](https://cdn.jsdelivr.net/gh/DaiShiBo369/PicBed@main/img/%E4%BA%8C%E7%BB%B4%E5%89%8D%E7%BC%80%E5%92%8C%E7%AE%97%E6%B3%95%E5%8F%AF%E8%A7%86%E5%8C%96f.png)
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 5B

让 AI 给我的实验报告打了个分：

**综合评分**：100 / 100（优秀）

优点：
- 2C 对 AI "矫枉过正"的观察挺有意思
- 4B 用了标准差和多次测量，比较严谨
- 3C、3D 对对拍和溢出的理解比较深入

建议：
- 检查链接能不能打开（助教要能访问）
- 可以加上修改前后的代码对比
- 可以讨论一下空间复杂度

（注：以上为 AI 评分和建议，仅供参考。我觉得"检查链接"和"代码对比"这两条比较实用）
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)

## 5C

如果矩阵需要频繁修改，二维前缀和每次更新要 $\mathcal{O}(nm)$，太慢了。

可以用的数据结构：

| 数据结构 | 修改 | 查询 | 说明 |
|----------|------|------|------|
| **二维树状数组** | $\mathcal{O}(\log n \log m)$ | $\mathcal{O}(\log n \log m)$ | 推荐首选 |
| 二维线段树 | $\mathcal{O}(\log n \log m)$ | $\mathcal{O}(\log n \log m)$ | 需要维护最大/最小值 |
| 二维分块 | $\mathcal{O}(1)$ | $\mathcal{O}(\sqrt{n}\sqrt{m})$ | 线段树太难写时考虑 |

推荐：二维树状数组，代码短、快、省内存。
[gemini](https://drive.google.com/file/d/1RuXKlv1PVpjTVF-xX4Fc545BD5Ud0y5a/view?usp=sharing, https://aistudio.google.com/app/prompts?state=%7B%22ids%22:%5B%221fkDwRHqnPg-cgQ_ZoWCIYemeGqk9QQ8_%22%5D,%22action%22:%22open%22,%22userId%22:%22108981880826629190648%22,%22resourceKeys%22:%7B%7D%7D&usp=sharing)
