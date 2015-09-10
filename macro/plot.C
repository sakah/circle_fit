TTree* read(char* txt)
{
   TTree *t =new TTree("t","t");
   t->SetMarkerStyle(20);
   t->ReadFile(txt,"iev/I:sig1:sig1in:sig1out:in1:in1sig:in1noise:sig2:sig2in:sig2out:in2:in2sig:in2noise:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:chi2");
   return t;
}
TTree* t1;
TTree* t2;
TTree* t3;
TTree* t4;
TH1F* get_chi2(TTree* t, char* hname, char* htitle, int max_chi2)
{
   char* hname1 = Form("h1-%s", hname);
   TH1F* h1 = new TH1F(hname1,Form("%s;reduced_chisquare",htitle),100,0,max_chi2);
   //t->Draw(Form("chi2/(num-5)>>%s", hname1),"chi2/(num-5)<5 && chi2/(num-5)>0");
   t->Draw(Form("chi2/(num-5)>>%s", hname1));
   return h1;
}
TH1F* get_ptres(TTree* t, char* hname, char* htitle)
{
   char* hname1 = Form("h2-%s", hname);
   TH1F* h1 = new TH1F(hname1,Form("%s;(ptfit-pthit)/pthit",htitle),100,-1,1);
   t->Draw(Form("(ptfit-pthit)/pthit>>%s", hname1));
   h1->Fit("gaus","","",-0.1,0.1);
   return h1;
}
TH1F* get_pzres(TTree* t, char* hname, char* htitle)
{
   char* hname1 = Form("h3-%s", hname);
   TH1F* h1 = new TH1F(hname1,Form("%s;(pzfit-pzhit)/pzhit",htitle),100,-2,2);
   t->Draw(Form("(pzfit-pzhit)/pzhit>>%s", hname1));
   h1->Fit("gaus","","",-0.3,0.3);
   return h1;
}
TH1F* get_z(TTree* t, char* hname, char* htitle)
{
   char* hname1 = Form("h4-%s", hname);
   TH1F* h1 = new TH1F(hname1,Form("%s;zfit-zhit", htitle),100,-100,100);
   t->Draw(Form("zfit-zhit>>%s", hname1));
   h1->Fit("gaus","","",-20.,20.);
   return h1;
}
void plot1()
{
   gStyle->SetOptFit();

   t1 = read("../output/run1/output.txt");
   t2 = read("../output/run2/output.txt");
   t3 = read("../output/run3/output.txt");
   t4 = read("../output/run4/output.txt");

   char* title1 = "Single/0%/0.02";
   char* title2 = "Multi/0%/0.02";
   char* title3 = "Single/10%/0.02";
   char* title4 = "Multi/0%/0.02";

   TH1F* h11 = get_chi2(t1, "t1", title1, 5);
   TH1F* h21 = get_chi2(t2, "t2", title2, 5);
   TH1F* h31 = get_chi2(t3, "t3", title3, 150);
   TH1F* h41 = get_chi2(t4, "t4", title4, 150);

   TH1F* h12 = get_ptres(t1, "t1", title1);
   TH1F* h22 = get_ptres(t2, "t2", title2);
   TH1F* h32 = get_ptres(t3, "t3", title3);
   TH1F* h42 = get_ptres(t4, "t4", title4);

   TH1F* h13 = get_pzres(t1, "t1", title1);
   TH1F* h23 = get_pzres(t2, "t2", title2);
   TH1F* h33 = get_pzres(t3, "t3", title3);
   TH1F* h43 = get_pzres(t4, "t4", title4);

   TH1F* h14 = get_z(t1, "t1", title1);
   TH1F* h24 = get_z(t2, "t2", title2);
   TH1F* h34 = get_z(t3, "t3", title3);
   TH1F* h44 = get_z(t4, "t4", title4);

   TCanvas* c1 = new TCanvas("c1");
   c1->Divide(2,2);
   c1->cd(1); c1->cd(1)->SetGrid(); h11->Draw();
   c1->cd(2); c1->cd(2)->SetGrid(); h21->Draw();
   c1->cd(3); c1->cd(3)->SetGrid(); h31->Draw();
   c1->cd(4); c1->cd(4)->SetGrid(); h41->Draw();

   TCanvas* c2 = new TCanvas("c2");
   c2->Divide(2,2);
   c2->cd(1); c2->cd(1)->SetGrid(); h12->Draw();
   c2->cd(2); c2->cd(2)->SetGrid(); h22->Draw();
   c2->cd(3); c2->cd(3)->SetGrid(); h32->Draw();
   c2->cd(4); c2->cd(4)->SetGrid(); h42->Draw();

   TCanvas* c3 = new TCanvas("c3");
   c3->Divide(2,2);
   c3->cd(1); c3->cd(1)->SetGrid(); h13->Draw();
   c3->cd(2); c3->cd(2)->SetGrid(); h23->Draw();
   c3->cd(3); c3->cd(3)->SetGrid(); h33->Draw();
   c3->cd(4); c3->cd(4)->SetGrid(); h43->Draw();

   TCanvas* c4 = new TCanvas("c4");
   c4->Divide(2,2);
   c4->cd(1); c4->cd(1)->SetGrid(); h14->Draw();
   c4->cd(2); c4->cd(2)->SetGrid(); h24->Draw();
   c4->cd(3); c4->cd(3)->SetGrid(); h34->Draw();
   c4->cd(4); c4->cd(4)->SetGrid(); h44->Draw();

   c1->Print("pdf1/c1.pdf");
   c2->Print("pdf1/c2.pdf");
   c3->Print("pdf1/c3.pdf");
   c4->Print("pdf1/c4.pdf");
}
void plot2()
{
   gStyle->SetOptFit();

   t1 = read("../output/run5/output.txt");
   t2 = read("../output/run6/output.txt");
   t3 = read("../output/run7/output.txt");
   t4 = read("../output/run8/output.txt");

   char* title1 = "Single/0%/0.01";
   char* title2 = "Multi/0%/0.01";
   char* title3 = "Single/10%/0.01";
   char* title4 = "Multi/0%/0.01";

   TH1F* h11 = get_chi2(t1, "t1", title1, 5);
   TH1F* h21 = get_chi2(t2, "t2", title2, 5);
   TH1F* h31 = get_chi2(t3, "t3", title3, 150);
   TH1F* h41 = get_chi2(t4, "t4", title4, 150);

   TH1F* h12 = get_ptres(t1, "t1", title1);
   TH1F* h22 = get_ptres(t2, "t2", title2);
   TH1F* h32 = get_ptres(t3, "t3", title3);
   TH1F* h42 = get_ptres(t4, "t4", title4);

   TH1F* h13 = get_pzres(t1, "t1", title1);
   TH1F* h23 = get_pzres(t2, "t2", title2);
   TH1F* h33 = get_pzres(t3, "t3", title3);
   TH1F* h43 = get_pzres(t4, "t4", title4);

   TH1F* h14 = get_z(t1, "t1", title1);
   TH1F* h24 = get_z(t2, "t2", title2);
   TH1F* h34 = get_z(t3, "t3", title3);
   TH1F* h44 = get_z(t4, "t4", title4);

   TCanvas* c1 = new TCanvas("c1");
   c1->Divide(2,2);
   c1->cd(1); c1->cd(1)->SetGrid(); h11->Draw();
   c1->cd(2); c1->cd(2)->SetGrid(); h21->Draw();
   c1->cd(3); c1->cd(3)->SetGrid(); h31->Draw();
   c1->cd(4); c1->cd(4)->SetGrid(); h41->Draw();

   TCanvas* c2 = new TCanvas("c2");
   c2->Divide(2,2);
   c2->cd(1); c2->cd(1)->SetGrid(); h12->Draw();
   c2->cd(2); c2->cd(2)->SetGrid(); h22->Draw();
   c2->cd(3); c2->cd(3)->SetGrid(); h32->Draw();
   c2->cd(4); c2->cd(4)->SetGrid(); h42->Draw();

   TCanvas* c3 = new TCanvas("c3");
   c3->Divide(2,2);
   c3->cd(1); c3->cd(1)->SetGrid(); h13->Draw();
   c3->cd(2); c3->cd(2)->SetGrid(); h23->Draw();
   c3->cd(3); c3->cd(3)->SetGrid(); h33->Draw();
   c3->cd(4); c3->cd(4)->SetGrid(); h43->Draw();

   TCanvas* c4 = new TCanvas("c4");
   c4->Divide(2,2);
   c4->cd(1); c4->cd(1)->SetGrid(); h14->Draw();
   c4->cd(2); c4->cd(2)->SetGrid(); h24->Draw();
   c4->cd(3); c4->cd(3)->SetGrid(); h34->Draw();
   c4->cd(4); c4->cd(4)->SetGrid(); h44->Draw();

   c1->Print("pdf1/c5.pdf");
   c2->Print("pdf1/c6.pdf");
   c3->Print("pdf1/c7.pdf");
   c4->Print("pdf1/c8.pdf");
}
void abc()
{
   gStyle->SetOptFit();
   t1 = read("debug2.txt");
   TProfile* prof = new TProfile("prof","dr vs z1;z1(cm);dr(cm)",100, -50, 50, 0, 15);
   t1->Draw("dr:zhit>>prof","dr<15 && zhit<100","profS");
   prof->Fit("pol1");
}
