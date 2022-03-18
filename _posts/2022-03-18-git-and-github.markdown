---
layout: post
title: Git / Github
date:   2022-03-18 01:22:22 +0900
categories: homework
---

## 루비 설치

[Rubyinstaller](https://rubyinstaller.org/)를 사용하여 루비를 설치한다.
___

## 지킬 설치

[Jekyll 사이트](https://jekyllrb-ko.github.io/)에 접속하면 빠른 시작 방법을 찾아볼 수 있다.

그 방법을 따라 차례대로 진행하면 지킬 설치가 완료된다.


```
[빠른 시작 방법]

gem install bundler jekyll

jekyll new my-awesome-site

cd my-awesome-site

bundle exec jekyll serve
```

## 중간에 webrick 오류가 발생하는 경우

```
bundle add webrick
```
위와 같은 코드를 입력한 후 그 전에 입력했던 코드를 다시 쳐보면 오류가 해결되는 것을 확인 할 수 있다.
___
## Git & Github
1. [Git 사이트](https://git-scm.com/)에 접속하여 [다운로드](https://git-scm.com/downloads)를 클릭하고 Git을 설치한다.
2. cmd에서 아래의 순서대로 진행한다.
```
cd my-awesome-site
git init .
git status
git add .
git commit -m "init"
config --global user.email ""
config --global user.name ""
git commit -m "init"
git log

```
3. [Github 페이지](https://github.com/)로 이동하여 회원가입을 진행한다.
4. 새로운 저장소(repository)를 만들어준다.
5. 아래의 코드를 차례로 입력해준다.
```
git remote add origin https://github.com/tnmin5h/tnmin5h.github.io.git
git branch -M main
git push -u origin main
```
6. 아래의 명령어를 입력해준다.
```
git add .
git commit -m "init"
```
___
## 명령어
* 저장소 초기화 명령어

    `git init [directory]`

    `git clone [repositoty]  [directory]`

* 버전 관리 (업데이트)

    `git pull` : 온라인 저장소 -> 로컬 저장소로 다시 다운로드 (협업할 때?)

    `git add [file...]` : 커밋할 파일들을 스테이지에 올림

    `git commit -m [message]` : 스테이징 파일 -> 버전 업데이트

    `git push` : 로컬 저장소 -> 온라인 저장소로 업로드 !

* 상태 확인

    `git status`

    `git log`