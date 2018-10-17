service --status-all
chkconfig --list
sed -e 's/{"url":/\n&/g' ~/.mozilla/firefox/*/sessionstore.js | cut -d\" -f4
dpkg -S `readlink -f /vmlinuz`
dig . NS

