# Git 


什么是版本库呢？版本库又名仓库，英文名repository，你可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”。

所以，创建一个版本库非常简单，

**首先，选择一个合适的地方，创建一个空目录：**

```cmd
$ mkdir learngit
$ cd learngit
$ pwd
/Users/michael/learngit
```

`pwd`命令用于显示当前目录。在我的Mac上，这个仓库位于`/Users/michael/learngit`。

**第二步，通过`git init`命令把这个目录变成Git可以管理的仓库：**
```cmd
$ git init
Initialized empty Git repository in /Users/michael/learngit/.git/
```
瞬间Git就把仓库建好了，而且告诉你是一个空的仓库（empty Git repository），细心的读者可以发现当前目录下多了一个`.git`的目录，这个目录是Git来跟踪管理版本库的，没事千万不要手动修改这个目录里面的文件，不然改乱了，就把Git仓库给破坏了。

如果你没有看到`.git`目录，那是因为这个目录默认是隐藏的，用`ls -ah`命令就可以看见。



**初始化一个Git仓库，使用`git init`命令。**

添加文件到Git仓库，分两步：

**使用命令`git add <file>`**，注意，可反复多次使用，添加多个文件；

**使用命令`git commit -m <message>`**，完成。

-----
## 时光穿梭机

**要随时掌握工作区的状态，使用`git status`命令**。

如果git status告诉你有文件被修改过，**用`git diff`可以查看修改内容**。

## 版本回退
HEAD指向的版本就是当前版本，因此，**Git允许我们在版本的历史之间穿梭，使用命令`git reset --hard commit_id`**。

穿梭前，**用`git log`可以查看提交历史，以便确定要回退到哪个版本。**

要重返未来，**用`git reflog`查看命令历史，以便确定要回到未来的哪个版本。**

## 工作区和缓存区
### 工作区（Working Directory）
就是你在电脑里能看到的目录，比如我的learngit文件夹就是一个工作区。

### 版本库（Repository）
工作区有一个隐藏目录`.git`，这个不算工作区，而是Git的版本库。

Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。


前面讲了我们把文件往Git版本库里添加的时候，是分两步执行的：

第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；

第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。

因为我们创建Git版本库时，Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改。

你可以简单理解为，**需要提交的文件修改通通放到暂存区，然后，一次性提交暂存区的所有修改。**

## 管理修改

>**第一次修改 -> git add -> 第二次修改 -> git commit**

第二次修改后的文档不会被提交。

**Git管理的是修改，当你用`git add`命令后，在工作区的第一次修改被放入暂存区，准备提交，但是，在工作区的第二次修改并没有放入暂存区，所以，`git commit`只负责把暂存区的修改提交了，也就是第一次的修改被提交了，第二次的修改不会被提交。**

提交后，用`git diff HEAD -- readme.txt`命令可以查看工作区和版本库里面最新版本的区别

提交第二次修改可以选择重新`git add` +` git commit -m`.

## 撤销修改
命令`git checkout -- readme.txt`意思就是，把`readme.txt`文件在工作区的修改全部撤销，这里有两种情况：

- **一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；**

- **一种是`readme.txt`已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。**

总之，就是让这个文件回到最近一次`git commit`或`git add`时的状态。

### 小结
场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令`git checkout -- file`。

场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令`git reset HEAD <file>`，就回到了场景1，第二步按场景1操作。

场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库。

## 删除文件
一般情况下，你通常直接在文件管理器中把没用的文件删了，或者用rm命令删了：
```cmd
$ rm test.txt
```
这个时候，Git知道你删除了文件，因此，工作区和版本库就不一致了，git status命令会立刻告诉你哪些文件被删除了：
```cmd
$ git status
On branch master
Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	deleted:    test.txt

no changes added to commit (use "git add" and/or "git commit -a")
```
现在你有两个选择，

**一是确实要从版本库中删除该文件，那就用命令`git rm`删掉，并且`git commit`**：
```cmd
$ git rm test.txt
rm 'test.txt'

$ git commit -m "remove test.txt"
[master d46f35e] remove test.txt
 1 file changed, 1 deletion(-)
 delete mode 100644 test.txt
 ```
现在，文件就从版本库中被删除了。

**另一种情况是删错了，因为版本库里还有呢，所以可以很轻松地把误删的文件恢复到最新版本**：
```cmd
$ git checkout -- test.txt
```
git checkout其实是用版本库里的版本替换工作区的版本，无论工作区是修改还是删除，都可以“一键还原”。

> **注意：从来没有被添加到版本库就被删除的文件，是无法恢复的！**
> 
### 小结
命令`git rm`用于删除一个文件。如果一个文件已经被提交到版本库，那么你永远不用担心误删，但是要小心，你只能恢复文件到最新版本，你会丢失最近一次提交后你修改的内容。

## 添加远程库
在GitHub上新建的这个learngit仓库还是空的，GitHub告诉我们，可以从这个仓库克隆出新的仓库，也可以把一个已有的本地仓库与之关联，然后，把本地仓库的内容推送到GitHub仓库。

**在本地的learngit仓库下运行命令关联仓库：**

```java
$ git remote add origin git@github.com:michaelliao/learngit.git
```

**添加后，远程库的名字就是origin，这是Git默认的叫法**，也可以改成别的，但是origin这个名字一看就知道是远程库。

下一步，就可以**把本地库的所有内容推送到远程库上：**

```cmd
$ git push -u origin master
Counting objects: 20, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (15/15), done.
Writing objects: 100% (20/20), 1.64 KiB | 560.00 KiB/s, done.
Total 20 (delta 5), reused 0 (delta 0)
remote: Resolving deltas: 100% (5/5), done.
To github.com:michaelliao/learngit.git
 * [new branch]      master -> master
Branch 'master' set up to track remote branch 'master' from 'origin'.
```
**把本地库的内容推送到远程，用`git push`命令，实际上是把当前分支`master`推送到远程。**

由于远程库是空的，我们第一次推送`master`分支时，**加上了`-u`参数，Git不但会把本地的`master`分支内容推送的远程新的`master`分支，还会把本地的`master`分支和远程的`master`分支关联起来**，在以后的推送或者拉取时就可以简化命令。

从现在起，只要本地作了提交，就可以通过命令：
```
$ git push origin master
```
**把本地master分支的最新修改推送至GitHub.**

### 小结
要关联一个远程库，使用命令`git remote add origin git@server-name:path/repo-name.git`；

关联后，使用命令`git push -u origin master`第一次推送master分支的所有内容；

此后，每次本地提交后，只要有必要，就可以使用命令`git push origin master`推送最新修改；

## 克隆远程库
远程库已经准备好了，下一步是用命令git clone克隆一个本地库：
```java
$ git clone git@github.com:michaelliao/gitskills.git
Cloning into 'gitskills'...
remote: Counting objects: 3, done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 3
Receiving objects: 100% (3/3), done.
```
注意把Git库的地址换成你自己的，然后进入gitskills目录看看，已经有README.md文件了：
```cmd
$ cd gitskills
$ ls
README.md
```
### 小结
要克隆一个仓库，首先必须知道仓库的地址，然后使用`git clone`命令克隆。

Git支持多种协议，包括https，但ssh协议速度最快。

## 创建和合并分支
### 小结
Git鼓励大量使用分支：

查看分支：`git branch`

创建分支：`git branch <name>`

切换分支：`git checkout <name>`或者`git switch <name>`

创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`

合并某分支到当前分支：`git merge <name>`

删除分支：`git branch -d <name>`

## 解决冲突
### 小结
当Git无法自动合并分支时，就必须首先解决冲突。解决冲突后，再提交，合并完成。

解决冲突就是把Git合并失败的文件手动编辑为我们希望的内容，再提交。

用`git log --graph`命令可以看到分支合并图。

## 分支管理策略
准备合并dev分支，请注意`--no-ff`参数，表示禁用`Fast forward`：
```cmd
$ git merge --no-ff -m "merge with no-ff" dev
Merge made by the 'recursive' strategy.
 readme.txt | 1 +
 1 file changed, 1 insertion(+)
```
因为本次合并要创建一个新的commit，所以加上-m参数，把commit描述写进去。

合并后，我们用`git log`看看分支历史：
```cmd
$ git log --graph --pretty=oneline --abbrev-commit
*   e1e9c68 (HEAD -> master) merge with no-ff
|\  
| * f52c633 (dev) add merge
|/  
*   cf810e4 conflict fixed
```

### 小结
Git分支十分强大，在团队开发中应该充分应用。

合并分支时，加上`--no-ff`参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而fast forward合并就看不出来曾经做过合并。
## Bug分支
Git提供了一个`stash`功能，可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作：

```cmd
$ git stash
Saved working directory and index state WIP on dev: f52c633 add merge
```
现在，用`git status`查看工作区，就是干净的（除非有没有被Git管理的文件），因此可以放心地创建分支来修复bug。

首先确定要在哪个分支上修复bug，假定需要在master分支上修复，就从master创建临时分支：
```cmd
$ git checkout master
Switched to branch 'master'
Your branch is ahead of 'origin/master' by 6 commits.
  (use "git push" to publish your local commits)

$ git checkout -b issue-101
Switched to a new branch 'issue-101'
```

现在修复bug，需要把“Git is free software ...”改为“Git is a free software ...”，然后提交：
```cmd
$ git add readme.txt 
$ git commit -m "fix bug 101"
[issue-101 4c805e2] fix bug 101
 1 file changed, 1 insertion(+), 1 deletion(-)
 ```
修复完成后，切换到master分支，并完成合并，最后删除issue-101分支：
``` cmd
$ git switch master
Switched to branch 'master'
Your branch is ahead of 'origin/master' by 6 commits.
  (use "git push" to publish your local commits)

$ git merge --no-ff -m "merged bug fix 101" issue-101
Merge made by the 'recursive' strategy.
 readme.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
 ```
太棒了，原计划两个小时的bug修复只花了5分钟！现在，是时候接着回到dev分支干活了！

```cmd
$ git switch dev
Switched to branch 'dev'

$ git status
On branch dev
nothing to commit, working tree clean
```
工作区是干净的，刚才的工作现场存到哪去了？用git stash list命令看看：

```cmd
$ git stash list
stash@{0}: WIP on dev: f52c633 add merge
```
工作现场还在，Git把stash内容存在某个地方了，但是需要恢复一下，有两个办法：

**一是用`git stash apply`恢复，但是恢复后，stash内容并不删除，你需要用`git stash drop`来删除；**

**另一种方式是用`git stash pop`，恢复的同时把stash内容也删了**

### 小结
修复bug时，我们会通过创建新的bug分支进行修复，然后合并，最后删除；

当手头工作没有完成时，先把工作现场`git stash`一下，然后去修复bug，修复后，再`git stash pop`，回到工作现场；

在master分支上修复的bug，想要合并到当前dev分支，可以用`git cherry-pick <commit>`命令，把bug提交的修改“复制”到当前分支，避免重复劳动。

## Feature 分支
### 小结
开发一个新feature，最好新建一个分支；

如果要丢弃一个没有被合并过的分支，可以通过`git branch -D <name>`强行删除。

## 多人协作
当你从远程仓库克隆时，实际上Git自动把本地的master分支和远程的master分支对应起来了，并且，远程仓库的默认名称是origin。

要查看远程库的信息，用`git remote`：
```cmd
$ git remote
origin
```
或者，用`git remote -v`显示更详细的信息：
```cmd
$ git remote -v
origin  git@github.com:michaelliao/learngit.git (fetch)
origin  git@github.com:michaelliao/learngit.git (push)
```
**上面显示了可以抓取和推送的origin的地址**。如果没有推送权限，就看不到push的地址。

### 推送分支
推送分支，就是把该分支上的所有本地提交推送到远程库。推送时，要指定本地分支，这样，Git就会把该分支推送到远程库对应的远程分支上：
```cmd
$ git push origin master
```
如果要推送其他分支，比如dev，就改成：
```cmd
$ git push origin dev
```
但是，并不是一定要把本地分支往远程推送，那么，哪些分支需要推送，哪些不需要呢？

`master`分支是主分支，因此要时刻与远程同步；

`dev`分支是开发分支，团队所有成员都需要在上面工作，所以也需要与远程同步；

`bug`分支只用于在本地修复`bug`，就没必要推到远程了，除非老板要看看你每周到底修复了几个`bug`；

`feature`分支是否推到远程，取决于你是否和你的小伙伴合作在上面开发。

### 拉取分支
因此，多人协作的工作模式通常是这样：

首先，可以试图用git push origin <branch-name>推送自己的修改；

如果推送失败，则因为远程分支比你的本地更新，需要先用git pull试图合并；

如果合并有冲突，则解决冲突，并在本地提交；

没有冲突或者解决掉冲突后，再用git push origin <branch-name>推送就能成功！

如果git pull提示no tracking information，则说明本地分支和远程分支的链接关系没有创建，用命令git branch --set-upstream-to <branch-name> origin/<branch-name>。

这就是多人协作的工作模式，一旦熟悉了，就非常简单。

### 小结
查看远程库信息，使用`git remote -v`；

本地新建的分支如果不推送到远程，对其他人就是不可见的；

从本地推送分支，使用`git push origin branch-name`，如果推送失败，先用`git pull`抓取远程的新提交；

在本地创建和远程分支对应的分支，使用`git checkout -b branch-name origin/branch-name`，本地和远程分支的名称最好一致；

建立本地分支和远程分支的关联，使用`git branch --set-upstream branch-name origin/branch-name`；

从远程抓取分支，使用`git pull`，如果有冲突，要先处理冲突。

## Rebase
### 小结
`rebase`操作可以把本地未`push`的分叉提交历史整理成直线；

`rebase`的目的是使得我们在查看历史提交的变化时更容易，因为分叉的提交需要三方对比。

## 标签管理
## 创建标签
在Git中打标签非常简单，首先，切换到需要打标签的分支上：
```cmd
$ git branch
* dev
  master
$ git checkout master
Switched to branch 'master'
```
然后，敲命令git tag <name>就可以打一个新标签：

```cmd 
$ git tag v1.0
```
可以用命令git tag查看所有标签：

```cmd
$ git tag
v1.0
```
默认标签是打在最新提交的commit上的。有时候，如果忘了打标签，比如，现在已经是周五了，但应该在周一打的标签没有打，怎么办？

方法是找到历史提交的commit id，然后打上就可以了：

```cmd
$ git log --pretty=oneline --abbrev-commit
12a631b (HEAD -> master, tag: v1.0, origin/master) merged bug fix 101
4c805e2 fix bug 101
e1e9c68 merge with no-ff
f52c633 add merge
cf810e4 conflict fixed
5dc6824 & simple
14096d0 AND simple
b17d20e branch test
d46f35e remove test.txt
b84166e add test.txt
519219b git tracks changes
e43a48b understand how stage works
1094adb append GPL
e475afc add distributed
eaadf4e wrote a readme file
```
比方说要对`add merge`这次提交打标签，它对应的`commit id`是f52c633，敲入命令：

```cmd
$ git tag v0.9 f52c633
```
再用命令git tag查看标签：

```cmd
$ git tag
v0.9
v1.0
```
注意，标签不是按时间顺序列出，而是按字母排序的。可以用`git show <tagname>`查看标签信息：

```cmd
$ git show v0.9
commit f52c63349bc3c1593499807e5c8e972b82c8f286 (tag: v0.9)
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Fri May 18 21:56:54 2018 +0800

    add merge

diff --git a/readme.txt b/readme.txt
...
```
可以看到，`v0.9`确实打在`add merge`这次提交上。

还可以创建带有说明的标签，用`-a`指定标签名，`-m`指定说明文字：

```cmd
$ git tag -a v0.1 -m "version 0.1 released" 1094adb
```
用命令`git show <tagname>`可以看到说明文字：

```cmd
$ git show v0.1
tag v0.1
Tagger: Michael Liao <askxuefeng@gmail.com>
Date:   Fri May 18 22:48:43 2018 +0800

version 0.1 released

commit 1094adb7b9b3807259d8cb349e7df1d4d6477073 (tag: v0.1)
Author: Michael Liao <askxuefeng@gmail.com>
Date:   Fri May 18 21:06:15 2018 +0800

    append GPL

diff --git a/readme.txt b/readme.txt
...
```

### 小结
命令`git tag <tagname>`用于新建一个标签，默认为HEAD，也可以指定一个`commit id`；

命令`git tag -a <tagname> -m "blablabla..."`可以指定标签信息；

命令`git tag`可以查看所有标签。

### 操作标签
### 小结
命令`git push origin <tagname>`可以推送一个本地标签；

命令`git push origin --tags`可以推送全部未推送过的本地标签；

命令`git tag -d <tagname>`可以删除一个本地标签；

命令`git push origin :refs/tags/<tagname>`可以删除一个远程标签。


















## 指令小结
```java
//命令行指令总结
//create a repository
$ mkdir <file>                创建一个文件
$ cd <file>                   进入一个文件
$ pwd                           显示当前文件路径

//add files to a repository
$ git add <file>                把文档放入暂存区
$ git commit -m <message>       把文档提交到分支

//查看状态
$ git status                    
$ git diff
//版本回溯
$ git log 
$ git log --pretty oneline
$ git reflog
$ git reset --hard commit_id

//管理修改
$ cat <file>
$ git diff HEAD -- <file> 

//撤回修改
$ git checkout -- <file>
$ git reset HEAD <file>

//删除文件
$ git rm <file>
$ git checkout -- <file>

//添加远程库
$ git remote add origin git@server-name:path/repo-name.git
$ git push -u origin master
$ git push origin master

//克隆远程库
$ git clone git@server-name:path/repo-name.git

//创建与合并分支
$ git checkout -b <branchname>
$ git branch
$ git merge
$ git checkout <branchname>
$ git branch -d <branchname>
$ git switch -c <branchname>
$ git switch <branchname>

//解决冲突
$ git log --graph --pretty=oneline --abbrev-commit

//分支管理策略
$ git merge --no-ff -m <message> <branchname>

//Bug分支
$ git stash
$ git stash list
$ git stash pop
$ git stash apply
$ git stash drop
$ git cherrypic <commit>

//Feature 分支
$ git branch -D <branchname>

// 多人协作
$ git remote
$ git remote -v
$ git push origin <branchname>
$ git checkout -b branch-name origin/branch-name
$ git pull
$ git branch --set-upstream branch-name origin/branch-name

// 创建标签
$ git show <tagname>
$ git tag <name> <commid-id>
$ git tag
$ git tag -a <tagname> -m "blablabla..."

//操作标签
$ git push origin <tagname>
$ git push origin --tags
$ git tag -d <tagname>
$ git push origin :refs/tags/<tagname>
```