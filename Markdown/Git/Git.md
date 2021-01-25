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
```