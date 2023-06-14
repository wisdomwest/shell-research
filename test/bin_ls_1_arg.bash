#!/bin/bash

################################################################################
# Description for the intranet check (one line, support Markdown syntax)
# Execute `/bin/ls -l`

################################################################################
# The variable 'compare_with_sh' IS OPTIONNAL
#
# Uncomment the following line if you don't want the output of the shell
# to be compared against the output of /bin/sh
#
# It can be useful when you want to check a builtin command that sh doesn't
# implement
# compare_with_sh=0

################################################################################
# The variable 'shell_input' HAS TO BE DEFINED
#
# The content of this variable will be piped to the student's shell and to sh
# as follows: "echo $shell_input | ./hsh"
#
# It can be empty and multiline
shell_input="/bin/ls -l"

################################################################################
# The variable 'shell_params' IS OPTIONNAL
#
# The content of this variable will be passed to as the paramaters array to the
# shell as follows: "./hsh $shell_params"
#
# It can be empty
# shell_params=""

################################################################################
# The function 'check_setup' will be called BEFORE the execution of the shell
# It allows you to set custom VARIABLES, prepare files, etc
# If you want to set variables for the shell to use, be sure to export them,
# since the shell will be launched in a subprocess
#
# Return value: Discarded
function check_setup()
{
export SHELL=/bin/zsh
export SESSION_MANAGER=local/rasputin:@/tmp/.ICE-unix/1759,unix/rasputin:/tmp/.ICE-unix/1759
export QT_ACCESSIBILITY=1
export COLORTERM=truecolor
export SSH_AGENT_LAUNCHER=gnome-keyring
export XDG_MENU_PREFIX=gnome-
export GNOME_DESKTOP_SESSION_ID=this-is-deprecated
export LESS_TERMCAP_se=
export LESS_TERMCAP_so=
export LC_ADDRESS=sw_KE
export GNOME_SHELL_SESSION_MODE=ubuntu
export LC_NAME=sw_KE
export SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
export XMODIFIERS=@im=ibus
export DESKTOP_SESSION=ubuntu
export LC_MONETARY=sw_KE
export GTK_MODULES=gail:atk-bridge
export PWD=/home/purple_quasar/ALX_SE/Projects/April/simple_shell
export LOGNAME=purple_quasar
export XDG_SESSION_DESKTOP=ubuntu
export XDG_SESSION_TYPE=wayland
export SYSTEMD_EXEC_PID=11977
export XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.58QV31
export HOME=/home/purple_quasar
export USERNAME=purple_quasar
export LC_PAPER=sw_KE
export LANG=en_US.UTF-8
export XDG_CURRENT_DESKTOP=ubuntu:GNOME
export VTE_VERSION=6800
export WAYLAND_DISPLAY=wayland-0
export GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/213c0559_9280_4727_bc87_9bde63ce37dd
export GNOME_SETUP_DISPLAY=:1
export XDG_SESSION_CLASS=user
export TERM=xterm-256color
export LC_IDENTIFICATION=sw_KE
export LESS_TERMCAP_mb=
export LESS_TERMCAP_me=
export LESS_TERMCAP_md=
export USER=purple_quasar
export GNOME_TERMINAL_SERVICE=:1.160
export DISPLAY=:0
export LESS_TERMCAP_ue=
export SHLVL=2
export LESS_TERMCAP_us=
export LC_TELEPHONE=sw_KE
export QT_IM_MODULE=ibus
export LC_MEASUREMENT=sw_KE
export XDG_RUNTIME_DIR=/run/user/1000
export LC_TIME=sw_KE
export XDG_DATA_DIRS=/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
export GDMSESSION=ubuntu
export DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
export LC_NUMERIC=sw_KE
export OLDPWD=/home/purple_quasar/ALX_SE/Projects/April/simple_shell

echo "Exported variables:"
env | grep -i 'sw_KE'
	return 0
}

################################################################################
# The function 'sh_setup' will be called AFTER the execution of the students
# shell, and BEFORE the execution of the real shell (sh)
# It allows you to set custom VARIABLES, prepare files, etc
# If you want to set variables for the shell to use, be sure to export them,
# since the shell will be launched in a subprocess
#
# Return value: Discarded
function sh_setup()
{
export SHELL=/bin/zsh
export SESSION_MANAGER=local/rasputin:@/tmp/.ICE-unix/1759,unix/rasputin:/tmp/.ICE-unix/1759
export QT_ACCESSIBILITY=1
export COLORTERM=truecolor
export SSH_AGENT_LAUNCHER=gnome-keyring
export XDG_MENU_PREFIX=gnome-
export GNOME_DESKTOP_SESSION_ID=this-is-deprecated
export LESS_TERMCAP_se=
export LESS_TERMCAP_so=
export LC_ADDRESS=sw_KE
export GNOME_SHELL_SESSION_MODE=ubuntu
export LC_NAME=sw_KE
export SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
export XMODIFIERS=@im=ibus
export DESKTOP_SESSION=ubuntu
export LC_MONETARY=sw_KE
export GTK_MODULES=gail:atk-bridge
export PWD=/home/purple_quasar/ALX_SE/Projects/April/simple_shell
export LOGNAME=purple_quasar
export XDG_SESSION_DESKTOP=ubuntu
export XDG_SESSION_TYPE=wayland
export SYSTEMD_EXEC_PID=11977
export XAUTHORITY=/run/user/1000/.mutter-Xwaylandauth.58QV31
export HOME=/home/purple_quasar
export USERNAME=purple_quasar
export LC_PAPER=sw_KE
export LANG=en_US.UTF-8
export XDG_CURRENT_DESKTOP=ubuntu:GNOME
export VTE_VERSION=6800
export WAYLAND_DISPLAY=wayland-0
export GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/213c0559_9280_4727_bc87_9bde63ce37dd
export GNOME_SETUP_DISPLAY=:1
export XDG_SESSION_CLASS=user
export TERM=xterm-256color
export LC_IDENTIFICATION=sw_KE
export LESS_TERMCAP_mb=
export LESS_TERMCAP_me=
export LESS_TERMCAP_md=
export USER=purple_quasar
export GNOME_TERMINAL_SERVICE=:1.160
export DISPLAY=:0
export LESS_TERMCAP_ue=
export SHLVL=2
export LESS_TERMCAP_us=
export LC_TELEPHONE=sw_KE
export QT_IM_MODULE=ibus
export LC_MEASUREMENT=sw_KE
export XDG_RUNTIME_DIR=/run/user/1000
export LC_TIME=sw_KE
export XDG_DATA_DIRS=/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
export GDMSESSION=ubuntu
export DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
export LC_NUMERIC=sw_KE
export OLDPWD=/home/purple_quasar/ALX_SE/Projects/April/simple_shell

echo "Exported variables:"
env | grep -i 'sw_KE'
	return 0
}

################################################################################
# The function `check_callback` will be called AFTER the execution of the shell
# It allows you to clear VARIABLES, cleanup files, ...
#
# It is also possible to perform additionnal checks.
# Here is a list of available variables:
# STATUS -> Path to the file containing the exit status of the shell
# OUTPUTFILE -> Path to the file containing the stdout of the shell
# ERROR_OUTPUTFILE -> Path to the file containing the stderr of the shell
# EXPECTED_STATUS -> Path to the file containing the exit status of sh
# EXPECTED_OUTPUTFILE -> Path to the file containing the stdout of sh
# EXPECTED_ERROR_OUTPUTFILE -> Path to the file continaing the stderr of sh
#
# Parameters:
#     $1 -> Status of the comparison with sh
#             0 -> The output is the same as sh
#             1 -> The output differs from sh
#
# Return value:
#     0  -> Check succeed
#     1  -> Check fails
function check_callback()
{
	status=$1

	return $status
}
