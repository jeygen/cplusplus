#!/usr/bin/perl
use strict;
use warnings;

# Define URLs and their corresponding hints
my %urls = (
    "https://www.google.com" => "A popular search engine",
    "https://www.perl.org" => "A scripting language's official website",
    "https://www.github.com" => "A platform for version control and collaboration",
);

# Select a random URL
my @keys = keys %urls;
my $random_url = $keys[int rand @keys];

# Present the URL to the user
print "Your URL is: $random_url\n";

# Ask the user if they want a hint
print "Would you like a hint (yes/no)? ";
chomp(my $input = <STDIN>);

# Provide the hint if the user wants it
if ($input =~ /^y(es)?$/i) {
    print "Hint: $urls{$random_url}\n";
} else {
    print "Okay, no hint for you!\n";
}

