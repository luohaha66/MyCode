############################################################
# Simple but Cute and Helpful (TM) Bash Settings
#
############################################################

# Cute shell shortcuts
alias ls='ls --sort=extension --color=auto'
alias psg='ps -aux | grep'
alias grep='grep --color=auto'
# some more ls aliases
alias ll='ls -alF --time-style=long-iso'
alias la='ls -A'
alias l='ls -CF'
alias show='apt-cache search'
alias get='sudo apt-get install'
alias dir='dir --color=auto'
alias vdir='vdir --color=auto'
alias grep='grep --color=auto'
alias fgrep='fgrep --color=auto'
alias egrep='egrep --color=auto'

# Git Commands
# Add and Commit are used as functions
alias gps='git push'
alias gpso='git push origin master'
alias gpl='git pull --rebase'
alias gplo='git pull origin master'
alias gs='git status'
alias gd='git diff'
alias gr='git reflog'
alias glf='git ls-files'
alias ga='git add'
alias gc='git commit -m'
alias gca='git commit --amend'
alias gl='git log'
alias gst='git stash'
alias gstp='git stash pop'
alias gb='git branch -v'
alias gba='git branch -a'

# Useful unarchiver!
function extract () {
        if [ -f $1 ] ; then
                case $1 in
                        *.tar.bz2)    tar xjf $1       ;;
                        *.tar.gz)     tar xzf $1       ;;
                        *.bz2)        bunzip2 $1       ;;
                        *.rar)        rar x $1         ;;
                        *.gz)         gunzip $1        ;;
                        *.tar)        tar xf $1        ;;
                        *.tbz2)       tar xjf $1       ;;
                        *.tgz)        tar xzf $1       ;;
                        *.zip)        unzip $1         ;;
                        *.Z)          uncompress $1    ;;
                        *)            echo "'$1' cannot be extracted via extract()" ;;
                esac
        else
                echo "'$1' is not a valid file"
        fi
}

# Change up a variable number of directories
# E.g:
#   up   -> cd ../
#   up 2 -> cd ../../
#   up 3 -> cd ../../../
function up {
    local count=$1
    if [ -z "${count}" ]; then
        count=1
    fi
    local path=""
    for i in $(seq 1 ${count}); do
        path="${path}../"
    done
    cd $path
}

# Colours have names too. Stolen from Arch wiki
txtblk='\[\e[0;30m\]' # Black - Regular
txtred='\[\e[0;31m\]' # Red
txtgrn='\[\e[0;32m\]' # Green
txtylw='\[\e[0;33m\]' # Yellow
txtblu='\[\e[0;34m\]' # Blue
txtpur='\[\e[0;35m\]' # Purple
txtcyn='\[\e[0;36m\]' # Cyan
txtwht='\[\e[0;37m\]' # White
bldblk='\[\e[1;30m\]' # Black - Bold
bldred='\[\e[1;31m\]' # Red
bldgrn='\[\e[1;32m\]' # Green
bldylw='\[\e[1;33m\]' # Yellow
bldblu='\[\e[1;34m\]' # Blue
bldpur='\[\e[1;35m\]' # Purple
bldcyn='\[\e[1;36m\]' # Cyan
bldwht='\[\e[1;37m\]' # White
unkblk='\[\e[4;30m\]' # Black - Underline
undred='\[\e[4;31m\]' # Red
undgrn='\[\e[4;32m\]' # Green
undylw='\[\e[4;33m\]' # Yellow
undblu='\[\e[4;34m\]' # Blue
undpur='\[\e[4;35m\]' # Purple
undcyn='\[\e[4;36m\]' # Cyan
undwht='\[\e[4;37m\]' # White
bakblk='\[\e[40m\]'   # Black - Background
bakred='\[\e[41m\]'   # Red
badgrn='\[\e[42m\]'   # Green
bakylw='\[\e[43m\]'   # Yellow
bakblu='\[\e[44m\]'   # Blue
bakpur='\[\e[45m\]'   # Purple
bakcyn='\[\e[46m\]'   # Cyan
bakwht='\[\e[47m\]'   # White
txtrst='\[\e[0m\]'    # Text Reset

# Prompt colours
atC="${txtgrn}"
nameC="${txtgrn}"
hostC="${txtgrn}"
pathC="${txtylw}"
gitC="${txtpur}"
pointerC="${txtgrn}"
normalC="${txtwht}"

# Red name for root
if [ "${UID}" -eq "0" ]; then
  nameC="${txtred}"
fi

# 'Safe' version of __git_ps1 to avoid errors on systems that don't have it
function gitPrompt {
  command -v __git_ps1 > /dev/null && __git_ps1 " (%s)"
}

# Patent Pending Prompt
export PS1="${nameC}\u${atC}@${hostC}\h:${pathC}\w${gitC}\$(gitPrompt)${pointerC}$ ${normalC}"

# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
eval "$('/d/Miniconda3/Scripts/conda.exe' 'shell.bash' 'hook')"
# <<< conda initialize <<<

# Welcome message
echo -ne "Hello, $USERNAME! It's "; date '+%A, %B %-d %Y'
echo
