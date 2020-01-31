# Git Basics
> Note: If you want to use already existing repository, simply skip first and second paragraph. 

## Initialization of Git repository

To create own repository simply type:
```
$ git init
```
Now, in your current directory will be added file: .git.

## Adding remote

To 'connect' your **local** repository with BitBucket repository type:
```
$ git remote add origin https://user@bitbucket.org/ddgg/oop_2019_odtwarzacz_wideo.git
```
Where **origin** is alias for http address. You will use this alias instead of typing long address. 

## Cloning remote repository
>Note: Cloning remote ropository is a fast way to set up git locally.  

If you want to use existing repository instead of create one paste code from BitBucket or type:
```
$ git clone https://user@bitbucket.org/ddgg/oop_2019_odtwarzacz_wideo.git
```

## Stay updated with remote repository

For instance let's have a situation when some people has already added some code at remote repository. 

To check if any updates occurred type:
```
$ git fetch origin
```
Now git fetch all of the updates. It seems fine, but fetch doesn't mean any files were downloaded. To download updated files ( or to pull) simply type:
```
$ git pull origin
```
Now you stay up-to-date with changes.

## Switching between branches

To switch branch, for instance from master to develop type:
```
$ git switch develop
```
You can also use a little bit older but still supported command:
```
$ git checkout develop
```