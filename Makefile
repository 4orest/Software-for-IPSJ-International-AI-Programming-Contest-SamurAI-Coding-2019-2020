all:
	cd manager; make all
	cd players; make all

testrun: all # 左が赤, 右が青
	manager/manager preliminary-fields/kk-field-1.dighere players/simplePlayer players/myPlayer >samples/testout.dighere

testallmap: all
	for i in `ls preliminary-fields/`
	do
		manager/manager preliminary-fields/$i players/simplePlayer players/myPlayer >testlog/$i
	done

TAGS:
	etags */*.cc */*.hh

clean:
	rm -f TAGS
	rm -f *.o *.d
	rm -rf *~ */*~ \#*\#

distclean: clean
	cd manager; make distclean
	cd players; make distclean
	cd samples; make distclean
	cd documents; make distclean
	cd webpage; make distclean
	cd icons; make distclean
	cd logos; make distclean
	cd sounds; make distclean
