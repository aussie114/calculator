#!/usr/bin/env wish
package require Tk
load ./tinyexpr.so

set font_spec {"TkfixedFont" 12}

wm title . "Calculator"
wm resizable . false false
. configure -background "#383c4a"

set label_options {
	-background "#383c4a"
	-foreground "#d1d8e1" 
}

set entry_options {
	-background "#444a58"
	-borderwidth 0
	-foreground "#c6cdd6"
	-highlightbackground "#2b2e39"
	-highlightcolor "#5294e2"
	-highlightthickness 1
	-insertbackground "#d3dae3"
	-relief "flat"
	-selectbackground "#5294e2"
	-selectforeground "#e7f0fb"
}

set text_options {
	-background "#444a58"
	-borderwidth 0
	-foreground "#c6cdd6"
	-highlightbackground "#2b2e39"
	-highlightcolor "#5294e2"
	-highlightthickness 1
	-insertbackground "#d3dae3"
	-selectbackground "#5294e2"
	-selectforeground "#e7f0fb"
}


proc on_entry_submitted {} {
    set expression [.input get]
    set result [calculate $expression]
	.output configure -state "normal"
	.output insert end [format "%s = %g\n" $expression $result]
	.output configure -state "disabled"
	.output see end
}

text .output {*}$text_options
.output configure -width 40 -height 15 -font font_spec -wrap "none" -state "disabled"

entry .input {*}$entry_options
.input configure -font font_spec -width 40
focus .input
bind . <KeyPress-KP_Enter> {on_entry_submitted}
bind . <KeyPress-Return> {on_entry_submitted}

pack .output .input

bind . <KeyPress-Escape> {exit}
