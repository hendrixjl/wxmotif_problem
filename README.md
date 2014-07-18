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


I have created a fairly minimal example program (MainApp.cpp) that reproduces my problem under RHEL 6.4. I compile it with the command:
   g++ -D__WXMOTIF__ -DLOG4CPP_HAS_WCHAR_T=0 -D_FILE_OFFSET_BITS=64 \
       -D_LARGE_FILES -DWXUSINGDLL -DWX_PRECOMP -DNO_GCC_PRAGMA \   
       -I/home/applique/wxgtk_gcc490/lib/wx/include/gtk2-ansi-release-2.6 \
       -I/home/applique/wxgtk_gcc490/include/wx-2.6/ \
       -I/home/applique/wxmotif_gcc490/include/wx-2.6 \
       -O0 -Wall -fmessage-length=0 -fno-strict-aliasing -Wundef -Wno-ctor-dtor-privacy \
       MainApp.cpp \
       -L/home/applique/wxmotif_gcc490/lib/ \
       -L/home/applique/wxgtk_gcc490/lib/ \
       -o Zeroize  \
       -lwx_motifd_core-2.6 -lwx_based-2.6 -lwx_gtk2_core-2.6 -lwx_base-2.6

You would need to change the -I and -L paths - of course - if you replicate this on your system.
