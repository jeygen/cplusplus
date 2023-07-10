#!/usr/bin/perl
use strict;
use warnings;
use File::Find;

find(sub {
    if (-f and m/.*~$/) {
        unlink $_ or warn "Couldn't unlink $_: $!";
    }
}, '.');

