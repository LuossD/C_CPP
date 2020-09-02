# Git

---把大象放进冰箱需要三步: 1、把冰箱门打开 2、把大象放进去 3、把冰箱门关上

## [一.Git、GitHub、GitLab三者之间的联系以及区别](https://www.cnblogs.com/leeyongbard/p/9777498.html)

在讲区别以及联系之前先简要的介绍一下，这三者都是什么(本篇文章适合刚入门的新手，大佬请出门左转)

### 1.什么是 Git?

Git 是一个版本控制系统。

版本控制是一种用于记录一个或多个文件内容变化，方便我们查阅特定版本修订情况的系统。

以前在没有使用版本控制的时候，我们通常在我们的项目根目录下这样命名项目：

project_v1、project_v1.1、project_v2等等，通过这种方式记录我们项目的不同版本的修改，

有的时候我们还会在不同版本的文件中写一个说明，记录此版本项目新增、修改，删除等操作。

这样的操作是很繁杂的，有的时候还可能因为一些非人为因素导致文件丢失这样的事故。

有了版本控制系统，我们就不用再手动进行一些繁杂的操作，并且对于文件丢失这种事故我们也不

用再担心，你可以随便回到历史记录的某个时刻。

 

早期出现的版本控制系统有：SVN、CVS等，它们是集中式版本控制系统，都有一个单一的集中管理

的服务器，保存所有文件的修订版本，而协同合作的开发人员都通过客户端连接到这台服务器，取出

最新的文件或者提交更新。

从网上找了一张图，展示一下它们的原理：

![img](https://img2018.cnblogs.com/blog/1302542/201810/1302542-20181012124216737-59642320.png)

而我们的主角 Git 是分布式版本控制系统。Git 已经成为越来越多开发者的青睐，因为分布式的优势是很显著的。

 

### 2.集中式和分布式版本控制系统的区别

集中式版本控制系统，版本库是集中存放在中央服务器的，工作的时候，用的是自己的电脑，所以，我们首先需要

从中央服务器上拉取最新的版本，然后开始工作，等工作完了，再把自己的工作提交到中央服务器。在这里借用廖

雪峰老师的一个比喻，中央服务器好比是一个图书馆，你要改其中的一本书，必须先要从图书馆里把书借出来，然

后更改，改完之后，再放回图书馆。

集中式版本控制系统的一个最大毛病就是**必须联网才能工作**，所以对于网络环境比较差的情况使用集中式版本控制

系统是一件比较让人头疼的事情。

 

分布式版本控制系统没有中央服务器的概念，我们使用相关的客户端提取的不只是最新的文件，而是把代码仓库完整

地镜像下来，相当于每个人的电脑都是一个完整的版本库，这样的话，任何一处协同工作的服务器出现故障，都可以

用任何一个镜像出来的本地仓库恢复。并且，即便在网络环境比较差的情况下也不用担心，因为版本库就在本地电脑

上。

下图是经典的git开发过程。

![img](https://bkimg.cdn.bcebos.com/pic/a71ea8d3fd1f4134ca7667d8251f95cad0c85ed6?)

**Git的功能特性：**

从一般开发者的角度来看，git有以下功能：

1、从服务器上克隆完整的Git仓库（包括代码和版本信息）到单机上。

2、在自己的机器上根据不同的开发目的，创建分支，修改代码。

3、在单机上自己创建的分支上提交代码。

4、在单机上合并分支。

5、把服务器上最新版的代码fetch下来，然后跟自己的主分支合并。

6、生成补丁（patch），把补丁发送给主开发者。

7、看主开发者的反馈，如果主开发者发现两个一般开发者之间有冲突（他们之间可以合作解决的冲突），就会要求他们先解决冲突，然后再由其中一个人提交。如果主开发者可以自己解决，或者没有冲突，就通过。

8、一般开发者之间解决冲突的方法，开发者之间可以使用pull 命令解决冲突，解决完冲突之后再向主开发者提交补丁。

 从主开发者的角度（假设主开发者不用开发代码）看，git有以下功能：

1、查看邮件或者通过其它方式查看一般开发者的提交状态。

2、打上补丁，解决冲突（可以自己解决，也可以要求开发者之间解决以后再重新提交，如果是开源项目，还要决定哪些补丁有用，哪些不用）。

3、向公共服务器提交结果，然后通知所有开发人员。

个人总结：

(1).分布式版本控制系统下的本地仓库包含代码库还有历史库，在本地就可以查看版本历史

(2).而集中式版本控制系统下的历史仓库是存在于中央仓库，每次对比与提交代码都必须连接到中央仓库

(3).多人开发时，如果充当中央仓库的Git仓库挂掉了，任何一个开发者都可以随时创建一个新的中央仓库然后同步就可

以恢复中央仓库

从网上找了一张图，展示一下它们的原理：

![img](https://img2018.cnblogs.com/blog/1302542/201810/1302542-20181012144216877-390762675.png)

 

3.GitHub 和 GitLab 都是基于 web 的 Git 仓库，使用起来二者差不多，它们都提供了分享开源项目的平台，

为开发团队提供了存储、分享、发布和合作开发项目的中心化云存储的场所。

GitHub 作为开源代码库，拥有超过 900 万的开发者用户，目前仍然是最火的开源项目托管平台，GitHub 同时

提供公共仓库和私有仓库，但如果使用私有仓库，是需要付费的。

 

GitLab 解决了这个问题，你可以在上面创建私人的免费仓库。

 

GitLab 让开发团队对他们的代码仓库拥有更多的控制，相比较 GitHub , 它有不少特色：

(1) 允许免费设置仓库权限；

(2) 允许用户选择分享一个 project 的部分代码；

(3) 允许用户设置 project 的获取权限，进一步提升安全性；

(4) 可以设置获取到团队整体的改进进度；

(5) 通过 innersourcing 让不在权限范围内的人访问不到该资源；

 

所以，从代码的私有性上来看，GitLab 是一个更好的选择。但是对于开源项目而言，GitHub 依然是代码托管的首选。

## 二.git版本的升级

2.17.1之前用git update

2.17.1之后用git update-git-for-windows

简单的术语：

向下兼容（Downward Compatible）又称**向后兼容（Backwards compatibility**）；对于软件来说，向下兼容的意思是，较高版本的程序能顺利处理较低版本程序的数据。 Git 在保持向后兼容方面表现很好。

## 三.将本地文件夹push到github仓库

```bash
1、（先进入项目文件夹）通过命令 git init 把这个目录变成git可以管理的仓库
   git init # 会生成.git目录，它是本地版本库，包含它的就是工作区
2、把文件添加到版本库中，使用命令 git add .添加到暂存区里面去，不要忘记后面的小数点“.”，意为添加文件夹下的所有文件
   git add .
   # Git的版本库里存了很多东西，其中最重要的就是称stage（或者叫index）的暂存区，还有Git为我们自动创建的第一个分支master，以及指向master的一个指针叫HEAD。
3、用命令 git commit告诉Git，把文件提交到仓库。引号内为提交说明
   git commit -m 'first commit'
   # 简单解释一下git commit命令，-m后面输入的是本次提交的说明，可以输入任意内容，当然最好是有意义的，这样你就能从历史记录里方便地找到改动记录。
   # 嫌麻烦不想输入-m "xxx"行不行？确实有办法可以这么干，但是强烈不建议你这么干，因为输入说明对自己对别人阅读都很重要。实在不想输入说明的童鞋请自行Google，我不告诉你这个参数。
4、关联到远程库
　　git remote add origin https://github.com/MeFirebird/-.git（origin是默认的仓库名字，你可以改为自己喜欢的名字）
6、把本地库的内容推送到远程，使用 git push命令，实际上是把当前分支master推送到远程。执行此命令后会要求输入用户名、密码，验证通过后即开始上传。
　　git push -u origin master
　　# 由于远程库是空的，我们第一次推送master分支时，加上了-u参数，Git不但会把本地的master分支内容推送到远程新的master分支，还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令。
　　
# 另外，push时需要输入github用户名和密码的方式是https的方式，也可以用ssh的方式，使用密钥对（公钥和私钥），这样每次推送的时候就不用输入了
```

![img](https://images2015.cnblogs.com/blog/987101/201703/987101-20170307170555016-1139738856.png)

推送成功后，可以立刻在GitHub页面中看到远程库的内容已经和本地一模一样。

从现在起，**只要本地作了提交**，就可以通过命令：

```bash
$ git push origin master
```

把本地`master`分支的最新修改推送至GitHub，现在，你就拥有了真正的分布式版本库！

**可能出现的问题**

[git 第一次上传本地代码到远程仓库，解决 ! [rejected\] master -> master (non-fast-forward)错误](https://www.cnblogs.com/yuanchao-blog/p/11730296.html)

当你第一次push的时候一般会遇到如下报错：

```bash
(base) PS D:\C_C++> git push cpp master
To https://github.com/LuossD/C_CPP
 ! [rejected]        master -> master (non-fast-forward)
error: failed to push some refs to 'https://github.com/LuossD/C_CPP'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

这种错误的主要原因是你的远程仓库的内容有改动但是你本地并没有拉去最新的代码所以会报错。

然后你如果直接pull又会有错误，如下：

```bash
warning: no common commits
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), 607 bytes | 2.00 KiB/s, done.
From https://github.com/LuossD/C_CPP
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> cpp/master
fatal: refusing to merge unrelated histories
```

**解决方法**

首先：

```bash
 git pull origin master --allow-unrelated-histories
 # 后面加上 --allow-unrelated-histories，把两段不相干的分支进行强行合并
```

linux中可能会出现vim编辑不用管直接保存退出就行

然后建议做完上一步之后再重新：

```bash
git add .

git commit -m '提交说明'

git push origin master
```

**详解原因：**

本文讲的是把git在最新2.9.2，合并pull两个不同的项目，出现的问题如何去解决

如果合并了两个不同的开始提交的仓库，在新的 git 会发现这两个仓库可能不是同一个，为了防止开发者上传错误，于是就给下面的提示

```bash
fatal: refusing to merge unrelated histories
```

如我在Github新建一个仓库，写了License，然后把本地一个写了很久仓库上传。这时会发现 github 的仓库和本地的没有一个共同的  commit 所以  git 不让提交，认为是写错了 origin ，如果开发者确定是这个 `origin` 就可以使用 --allow-unrelated-histories 告诉 git 自己确定。

遇到无法提交的问题，一般先pull 也就是使用 git pull origin master 这里的 origin 就是仓库，而 master 就是需要上传的分支，因为两个仓库不同，发现 git 输出 refusing to merge unrelated histories 无法 pull 内容。

**因为他们是两个不同的项目**，要把两个不同的项目合并，git需要添加一句代码，在 git pull 之后，这句代码是在git 2.9.2版本发生的，最新的版本需要添加 --allow-unrelated-histories 告诉 git 允许不相关历史合并

假如我们的源是origin，分支是master，那么我们需要这样写 git pull origin master --allow-unrelated-histories **如果有设置了默认上传分支就可以用下面代码**

```bash
 git pull --allow-unrelated-histories 
```

这个方法只解决因为两个仓库有不同的开始点，也就是两个仓库没有共同的 commit 出现的无法提交。如果使用本文的方法还无法提交，需要看一下是不是发生了冲突，解决冲突再提交

**出现这个问题的根本：**

```
Skip this step if you’re importing an existing repository.

  Initialize this repository with a README
This will let you immediately clone the repository to your computer.
```

因为我在新建仓库时用README初始化了仓库，**如果用一个已有仓库导入其中就不用初始化了，这样就可以直接把本地仓库的内容推送到GitHub仓库。**

## 四.git原理

![img](https://images2017.cnblogs.com/blog/318519/201710/318519-20171026134145519-1705706787.png)

## 五.git常用命令

### 1.Git fetch pull 的应用, git 多人同时修改一个文件后的合并

Git中从远程的分支获取最新的版本到本地有这样2个命令：

1. git fetch：相当于是从远程获取最新版本到本地，不会自动merge

```bash
git fetch origin master
# 从远程的origin仓库的master分支下载代码到本地的origin master
git log -p master  origin/master
# 比较本地的master分支和origin/master分支的差别
git merge origin/master
# 把远程下载下来的代码合并到本地仓库，远程的和本地的合并
```

使用git log后末尾出现：，如果要退出按q即可。

上述过程其实可以用以下更清晰的方式来进行：

```bash
git fetch origin master:tmp
# 从远程的origin仓库的master分支下载到本地并新建一个分支temp
git diff tmp 
# 比较master分支和temp分支的不同
git merge tmp
# 合并temp分支到master分支

如果不想要temp分支了，可以删除此分支
git branch -d temp
# 删除temp
```

2. git pull：相当于是从远程获取最新版本并merge到本地

```bash
git pull origin master
```

上述命令其实相当于git fetch 和 git merge，在实际使用中，git fetch更安全一些，因为在merge前，我们可以查看更新情况，然后再决定是否合并。

补充：

git push origin + 远程分支名字  //将本地分⽀提交⾄指定远程分⽀；

git pull origin develop 从develop分支更新代码。

### 2.git版本回退

git reset就是当我们提交了错误的内容后进行回退使用的命令。

git reset 版本号，就是回退到该版本号上。

通常我们使用git reset HEAD就是回退到当前版本，git reset HEAD^回退到上一版本

**方法1**： git reset --hard HEAD ^  ( ^ 表示回到上一个版本，如果需要回退到上上个版本的话，将HEAD ^ 改成HEAD^^, 以此类推。那如果要回退到前100个版本，这种方法肯定不方便，我们可以使用简便命令操作：git reset --hard HEAD~100 );

**即方法2** ：git reset --hard 版本号 ，但是现在的问题是加入我已经关掉了命令行或者第三个版本的版本号，我并不知道？那么要如何知道第三个版本的版本号呐。可以通过如下命令获取到版本号： git reflog  

**git reset 加不加 --hard的区别：**

说明 git reset HEAD 会把暂存区恢复成HEAD，我们发现添加了错误的内容，此时我们**只是做了add 操作，就是将修改了内容添加到了暂存区，还没有执行commit，所以还没有生成版本号**，当前的版本号对应的内容，还是你add之前的内容，所以我们只需要将代码回退到当前版本就行，该操作不影响工作区。

git reset --hard HEAD 命令 会将工作区和暂存区恢复成HEAD。始终要注意这git reset --hard是一个潜在的危险命令，因为它会丢弃所有未提交的更改。为了安全起见，在使用前git status，请务必检查其输出是否干净（即为空）。

### 3.git log 与git reflog

git log可以显示所有提交过的版本信息，不包括已经被删除的 commit 记录和 reset 的操作；

git reflog是显示所有的操作记录，包括提交，回退的操作。一般用来找出操作记录中的版本号，进行回退。

git reflog常用于恢复本地的错误操作。

场景：我们commit了一个操作，发现提交的是错误的，我们进行了回退，git reset HEAD^,也进行了checkout 操作，就是把工作区的文件也回退还原了，这时候发现commit的没有问题。等于说删了不该删的了，咋整，想再回退到删除之前的。找到之前的版本号进行回退，使用git log发现那个提交的版本号记录根本不存在了。**说白了就是：在回退以后又想再次回到之前的版本！**

这时候 git reflog就体现作用了。

### 4.git status

`git status`命令用于显示工作目录和暂存区的状态。使用此命令能看到哪些修改被暂存到了, 哪些没有, 哪些文件没有被Git tracked到。**即列出当前目录所有还没有被git管理的文件和被git管理且被修改但还未提交(git commit)的文件**.`git status`**不显示已经`commit`到项目历史中去的信息**。看项目历史的信息要使用`git log`.

提示：每次修改,如果不 add 到暂存区,那就不会加入到 commit 中

我们可以git add后加一个点（.）来将当前目录下全部文件包含子目录中的全部文件加入暂存区。

我修改了好几个文件是之前git add到暂存区过的，要怎么直接添加这几个文件呢，我们可以通过git add -u将之前git追踪过的文件一次性添加到暂存区。

> 附：nothing added to commit but untracked files present解决方法
>
> **解决办法**
>
> 将未提交但不需要的文件添加到git忽略文件 **.gitignore**
>
> 1.git status
>
> 2.将要忽略的文件写入到.gitignore
>
> ```bash
> vim .gitignore
> ```
>
> 3.追加如下内容（根据自己的提示添加）
>
> ```bash
> /target/ 
> zblog.iml
> ```
>
> **PS:注意实际路径可以用 *模糊操作**
>
> 4.将这些文件或文件夹add进去
>
> ```bash
> git add /target/.
> git add zblog.iml
> ```

### 5.git pull的时候发生冲突的解决方法之“error: Your local changes to the following files would be overwritten by merge”

**方法一、stash**

```bash
1 git stash # 其中stash@{0}就是刚才保存的标记
2 git pull  # 暂存了本地修改之后，就可以pull了
3 git stash pop # 弹出最上面的
```

接下来diff一下此文件看看自动合并的情况，并作出相应修改。

git stash: 备份当前的工作区的内容，从**最近的一次提交中读取相关内容，让工作区保证和上次提交的内容一致**。同时，将当前的工作区内容保存到**Git栈中**。
git stash pop: 从Git栈中**读取最近一次保存的内容**，恢复工作区的相关内容。由于可能存在多个Stash的内容，所以用栈来管理，pop会从最近的一个stash中读取内容并恢复。
git stash list: 显示Git栈内的所有备份，可以利用这个列表来决定从那个地方恢复。
git stash clear: 清空Git栈。此时使用gitg等图形化工具会发现，原来stash的哪些节点都消失了。

> 系统提示如下类似的信息：
> Auto-merging Linux_C++ .md
> CONFLICT (content): Merge conflict in Linux_C++ .md
>
> 意思就是系统自动合并修改的内容，但是其中有冲突，需要解决其中的冲突。
>
> 解决文件中冲突的的部分
>
> 打开冲突的文件，会看到类似如下的内容：
>
> git冲突内容
>
> 其中Updated upstream 和=====之间的内容就是pull下来的内容，====和stashed changes之间的内容就是本地修改的内容。碰到这种情况，git也不知道哪行内容是需要的，所以要自行确定需要的内容。
>
> 解决完成之后，就可以正常的提交了。

**方法二、放弃本地修改，直接覆盖**

```bash
1 git reset --hard
2 git pull
```

git stash :

可用来暂存当前正在进行的工作， 比如想pull 最新代码， 又不想加新commit， 或者另外一种情况，为了fix 一个紧急的bug,  先stash, 使返回到自己上一个commit, 改完bug之后再stash pop, 继续原来的工作。
 基础命令：

```bash
 git stash
 do some work
 git stash pop
```

进阶：

 Git stash save "work in progress for foo feature"
 当你多次使用’git stash’命令后，你的栈里将充满了未提交的代码，这时候你会对将哪个版本应用回来有些困惑，

’git stash list’ 命令可以将当前的Git栈信息打印出来，你只需要将找到对应的版本号，例如使用’git stash apply stash@{1}’就可以将你指定版本号为stash@{1}的工作取出来，当你将所有的栈都应用回来的时候，可以使用’git stash clear’来将栈清空。

```bash
git stash          # save uncommitted changes
# pull, edit, etc.
git stash list     # list stashed changes in this git
git show stash@{0} # see the last stash 
git stash pop      # apply last stash and remove it from the list
git stash --help   # for more info
```

扩展：

git pull会把本地未提交修改覆盖吗？

> 分两种情况：1无冲突，2有冲突
>
> 无冲突时，本地未提交修改不会被zhi覆盖，能够执行pull。
> 有冲突时，提示“Your local changes to the following files would be overwritten by merge”，本次pull执行失败，并且不会拉取远程代码，不用担心。

> 没有 add 的文件，不会被覆盖。add 了文件没有 commit，不能 pull。commit 了之后 pull 有冲突，会自行解决或者提示需要编辑。只要 commit 过，都可以用 git reflog 找回。
>
> git库版本与本地库版本冲突：个人定义为就是git库版本与本地库版本不匹配，详细地说就是我们从git库clone克隆下来的版本，经过修改后提交并合并成新版本，但是后来又将git库的该版本撤销了，而本地没有撤销该版本，此时就是本地库拥有此版本而git库中没有此版本。这样在使用git pull或git pull origin master可能会出现：“Your local changes to the following files would be overwritten by merge”或"PULL  不可用，因为您尚有未合并的文件“或"自动合并失败，修正冲突后提交修正后的结果"“Your local changes to the following files would be overwritten by merge”这样的错误，意思就是你的本地修改以下文件将被覆盖合并。

### 6.git一次提交多个文件时写了一个提交信息结果每个文件都是那个信息，如何修改？如何为每个文件写提交信息？

git 一次add多个文件的方法

```bash
git add file_1 file_2 file_3
```

如果文件已经被追踪，多个文件修改后，可以直接git add -u。

如果要为每个文件写不同的提交信息，可使用如下shell脚本

```bash
#!/bin/sh

PROJECT_DIR=.

for FILE in ${PROJECT_DIR}/*
do
    git add ${FILE}
    git commit 
done
# 还没试过，先放这里备用
```

回归正题：

```bash
git add add1.txt
git add add2.txt
git commit -m "add file"

# 这样会导致两个文件的提交说明是一样的，而且我已经提交到了远程仓库了，这时候如果想修改提交信息，目前采用如下方法：
git reset HEAD
git add add1.txt
git commit -m “add one file”
git add add2.txt
git commit -m “add another file”
git push -f test master
如果不使用-f强制push，会报错：
 ! [rejected]        master -> master (non-fast-forward)
error: failed to push some refs to 'https://github.com/LuossD/testgit'
hint: Updates were rejected because the tip of your current branch is behind
hint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
此时如果用“git push”会报错，因为我们本地库HEAD指向的版本比远程库的要旧！
```

如果你只想修改最后一次注释（就是最新的一次提交），那好办：

```bash
git commit --amend
```

修改之前的某次注释

```bash
输入：
git rebase -i HEAD~2
最后的数字2指的是显示到倒数第几次 比如这个输入的2就会显示倒数的两次注释（最上面两行）
```

你想修改哪条注释 就把哪条注释前面的`pick`换成`edit`。

1. 然后：（接下来的步骤Terminal会提示）
   `git commit --amend`
2. 修改注释，保存并退出后，输入：
   git rebase --continue

### 修改之前的某几次注释

修改多次的注释其实步骤和上面的一样，不同点在于：

1. 同上
2. 你可以将**多个**想修改的commit注释前面的`pick`换成`edit`
3. **依次修改**你的注释（顺序是从旧到新），Terminal基本都会提示你接下来的操作，每修改一个注释都要重复上面的1和2步，直到修改完你所选择的所有注释

已经将代码push**到远程仓库**

首先，你把最新的版本从远程仓库先pull下来，修改的方法都如上，最后修改完成后，强制push到远程仓库：
 `git push --force origin master`
 **注：很重要的一点是，你最好保证在你强制push之前没有人提交代码，如果在你push之前有人提交了新的代码到远程仓库，然后你又强制push，那么会被你的强制更新覆盖！！！**另外使用rebase后操作一定要做完，不然出现master|RENASE，搞的头大，**此时**如果想要放弃当前rebase操作，用 `git rebase --abort`。

最后，可以检查一下远程的提交记录~~

暂时没搜到如何一次写入多条提交信息！使用git时尽量小心，里面有太多命令太多坑了。

## 六.git文件常见下标符号说明

git的文件上的图标，可以反映出当前文件或者文件夹的状态。

　　1、正常的：**绿色的对号**

　　2、被修改过的：**红色感叹号**

　　3、新添加的：**蓝色的加号**

　　4、**未受控的（无版本控制的）：蓝色的问号**（把带红色x的文件提交之后，文件就变为蓝色问号，表示本地还有一个副本，但是仓库浏览器里已经不存在该文件了）

　　5、忽略不受控的：灰色的减号

　　6、删除的：红色的x号（只是把文件打上删除的标记，文件依然存在于本地仓库里）

　　7、有冲突的：**黄色的感叹号**

