#!/bin/bash
exec { 'kill_killmenow_process':
  command => 'pkill killmenow',
  path    => ['/bin', '/usr/bin'],
  onlyif  => "pgrep killmenow"
}
