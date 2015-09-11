static bool done_setup=false;
void setup()
{
   if (done_setup) return;
   gROOT->ProcessLine(".L run.C");
   gROOT->ProcessLine(".L plot.C");
   done_setup=true;
};
void thre1()
{
   setup();
   Run run1(1, "setup.txt");
   Run run2(2, "setup.txt");
   Run run3(3, "setup.txt");
   Run run4(4, "setup.txt");
   Plot plot; plot.plot(1,run1,run2,run3,run4);
}
void thre2()
{
   setup();
   Run run1(5, "setup.txt");
   Run run2(6, "setup.txt");
   Run run3(7, "setup.txt");
   Run run4(8, "setup.txt");
   Plot plot; plot.plot(2,run1,run2,run3,run4);
}
void thre3()
{
   setup();
   Run run1(9,  "setup.txt");
   Run run2(10, "setup.txt");
   Run run3(11, "setup.txt");
   Run run4(12, "setup.txt");
   Plot plot; plot.plot(3,run1,run2,run3,run4);
}
void thre4()
{
   setup();
   Run run1(13, "setup.txt");
   Run run2(14, "setup.txt");
   Run run3(15, "setup.txt");
   Run run4(16, "setup.txt");
   Plot plot; plot.plot(4,run1,run2,run3,run4);
}
void all()
{
   thre1();
   thre2();
   thre3();
   thre4();
}

