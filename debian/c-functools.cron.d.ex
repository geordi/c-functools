#
# Regular cron jobs for the c-functools package
#
0 4	* * *	root	[ -x /usr/bin/c-functools_maintenance ] && /usr/bin/c-functools_maintenance
