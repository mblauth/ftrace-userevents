#!/bin/bash

debugfs="/sys/kernel/debug/tracing"

file="/lib64/libc.so.6"
strlenSymbol=$(objdump -t "$file" | grep strlen | head -1 | cut -d" " -f1 | sed 's/0*/0x/')

echo "p:strlen ${file}:${strlenSymbol}" > ${debugfs}/uprobe_events
echo 1 > ${debugfs}/events/uprobes/strlen/enable

trace-cmd record -F -e uprobes ./ftrace_userevents

echo 0 > ${debugfs}/events/uprobes/strlen/enable
echo > ${debugfs}/uprobe_events

trace-cmd report
