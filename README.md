wxmotif_problem
===============

In support of http://stackoverflow.com/questions/24830584/segfault-and-the-disassembly-is-different-between-objdump-and-gdb


See wxFrame::DoCreate location 2083c6:
and wxFrame::GetMainWidget location 209d5e:


I build WxMotif using:
./configure --with-motif --prefix=$PWD/../wxmotif_gcc447 --enable-debug
make
make install

I got the source (wxMotif-2.6.3.tar.gz) from http://sourceforge.net/projects/wxwindows/files/wxMotif/2.6.3/
