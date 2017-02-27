all: recitewords.exe
recitewords.exe: extracttest.cpp recite.dll
	cl -GX -o recitewords.exe extracttest.cpp recite.lib

recite.dll: init.cpp changeclass.cpp diction.cpp remark.cpp tofile.cpp example.cpp testen.cpp testword.cpp testprocess.cpp extractword.cpp\
	textp.cpp recitebook.cpp justice.cpp extrinit.cpp
	cl -LD -o recite.dll init.cpp changeclass.cpp diction.cpp remark.cpp tofile.cpp example.cpp testen.cpp testword.cpp testprocess.cpp\
		extractword.cpp textp.cpp recitebook.cpp justice.cpp extrinit.cpp

clean: 
	del *.exe *.obj *.dll *.exp *.lib