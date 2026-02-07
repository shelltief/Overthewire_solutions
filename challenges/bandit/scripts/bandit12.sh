cd "$(mktemp -d)" && cp "$HOME"/data.txt . || kill -INT $$
xxd -r data.txt outfile
file --mime-type -b outfile # should print : application/gzip
mv outfile outfile.gz
gunzip outfile.gz
file --mime-type -b outfile # should print : application/x-bzip2
bunzip2 outfile
file --mime-type -b outfile.out # should print : application/gzip
mv outfile.out outfile.gz
gunzip outfile.gz
file --mime-type -b outfile # should print : application/x-tar
tar -xf outfile
file --mime-type -b data5.bin # should print : application/x-tar
tar -xf data5.bin
file --mime-type -b data6.bin # should print : application/x-bzip2
bunzip2 data6.bin
file --mime-type -b data6.bin.out # should print : application/x-tar
tar -xf data6.bin.out
file --mime-type -b data8.bin # should print : application/gzip
mv data8.bin data8.gz
gunzip data8.gz
