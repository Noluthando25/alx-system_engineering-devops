#!/usr/bin/bash
exec { 'pkill killmenow':
  path => 'usr/bin':/usr/sbin:/bin'
}

