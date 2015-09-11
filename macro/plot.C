#include "TStyle.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TCanvas.h"
class Run
{
   public:
      Run(int id, double diff_thre)
      {
         plot_id = id;
         diff_threshold = diff_thre;
      };
      void add_data(int id, double max_chi2, char* data, char* title)
      {
         if (id==0) { max_chi2_1 = max_chi2; t1 = read(data); sprintf(title1, "%s/%5.4lf", title, diff_threshold); }
         if (id==1) { max_chi2_2 = max_chi2; t2 = read(data); sprintf(title2, "%s/%5.4lf", title, diff_threshold); }
         if (id==2) { max_chi2_3 = max_chi2; t3 = read(data); sprintf(title3, "%s/%5.4lf", title, diff_threshold); }
         if (id==3) { max_chi2_4 = max_chi2; t4 = read(data); sprintf(title4, "%s/%5.4lf", title, diff_threshold); }
      };
      void plot()
      {
         gStyle->SetOptStat(111111);
         gStyle->SetOptFit();

         TH1F* h11 = get_chi2(t1, "t1", title1, max_chi2_1);
         TH1F* h21 = get_chi2(t2, "t2", title2, max_chi2_2);
         TH1F* h31 = get_chi2(t3, "t3", title3, max_chi2_3);
         TH1F* h41 = get_chi2(t4, "t4", title4, max_chi2_4);

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

         TCanvas* c1 = new TCanvas("c1", "chi2");
         c1->Divide(2,2);
         c1->cd(1); c1->cd(1)->SetGrid(); h11->Draw();
         c1->cd(2); c1->cd(2)->SetGrid(); h21->Draw();
         c1->cd(3); c1->cd(3)->SetGrid(); h31->Draw();
         c1->cd(4); c1->cd(4)->SetGrid(); h41->Draw();

         TCanvas* c2 = new TCanvas("c2", "ptres");
         c2->Divide(2,2);
         c2->cd(1); c2->cd(1)->SetGrid(); h12->Draw();
         c2->cd(2); c2->cd(2)->SetGrid(); h22->Draw();
         c2->cd(3); c2->cd(3)->SetGrid(); h32->Draw();
         c2->cd(4); c2->cd(4)->SetGrid(); h42->Draw();

         TCanvas* c3 = new TCanvas("c3", "pzres");
         c3->Divide(2,2);
         c3->cd(1); c3->cd(1)->SetGrid(); h13->Draw();
         c3->cd(2); c3->cd(2)->SetGrid(); h23->Draw();
         c3->cd(3); c3->cd(3)->SetGrid(); h33->Draw();
         c3->cd(4); c3->cd(4)->SetGrid(); h43->Draw();

         TCanvas* c4 = new TCanvas("c4", "zpos");
         c4->Divide(2,2);
         c4->cd(1); c4->cd(1)->SetGrid(); h14->Draw();
         c4->cd(2); c4->cd(2)->SetGrid(); h24->Draw();
         c4->cd(3); c4->cd(3)->SetGrid(); h34->Draw();
         c4->cd(4); c4->cd(4)->SetGrid(); h44->Draw();

         c1->Print(Form("pdf/chi2/c%d.pdf",  plot_id));
         c2->Print(Form("pdf/ptres/c%d.pdf", plot_id));
         c3->Print(Form("pdf/pzres/c%d.pdf", plot_id));
         c4->Print(Form("pdf/zpos/c%d.pdf",  plot_id));
      };
   private:
      int plot_id;
      double diff_threshold;
      TTree *t1;
      TTree *t2;
      TTree *t3;
      TTree *t4;
      double max_chi2_1;
      double max_chi2_2;
      double max_chi2_3;
      double max_chi2_4;
      char title1[32];
      char title2[32];
      char title3[32];
      char title4[32];
      char pdf1[32];
      char pdf2[32];
      char pdf3[32];
      char pdf4[32];
      TTree* read(char* txt)
      {
         TTree *t =new TTree("t","t");
         t->SetMarkerStyle(20);
         t->ReadFile(txt,"iev/I:sig1:sig1in:sig1out:in1:in1sig:in1noise:sig2:sig2in:sig2out:in2:in2sig:in2noise:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:chi2");
         return t;
      };
      TH1F* get_chi2(TTree* t, char* hname, char* htitle, double max_chi2)
      {
         char* hname1 = Form("h1-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (chi2);reduced_chisquare",htitle),100,0,max_chi2);
         //t->Draw(Form("chi2/(num-5)>>%s", hname1),"chi2/(num-5)<5 && chi2/(num-5)>0");
         t->Draw(Form("chi2/(num-5)>>%s", hname1));
         return h1;
      };
      TH1F* get_ptres(TTree* t, char* hname, char* htitle)
      {
         char* hname1 = Form("h2-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (ptres);(ptfit-pthit)/pthit",htitle),100,-1,1);
         t->Draw(Form("(ptfit-pthit)/pthit>>%s", hname1));
         h1->Fit("gaus","","",-0.1,0.1);
         return h1;
      };
      TH1F* get_pzres(TTree* t, char* hname, char* htitle)
      {
         char* hname1 = Form("h3-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (pzres);(pzfit-pzhit)/pzhit",htitle),100,-2,2);
         t->Draw(Form("(pzfit-pzhit)/pzhit>>%s", hname1));
         h1->Fit("gaus","","",-0.3,0.3);
         return h1;
      };
      TH1F* get_z(TTree* t, char* hname, char* htitle)
      {
         char* hname1 = Form("h4-%s", hname);
         TH1F* h1 = new TH1F(hname1,Form("%s (zpos);zfit-zhit (cm)", htitle),100,-100,100);
         t->Draw(Form("zfit-zhit>>%s", hname1));
         h1->Fit("gaus","","",-20.,20.);
         return h1;
      };
};
void run1()
{
   Run run(1, 0.02);
   run.add_data(0, 5,   "../output/run1/output.txt", "Run1/Single/0%");
   run.add_data(1, 5,   "../output/run2/output.txt", "Run2/Multi/0%");
   run.add_data(2, 150, "../output/run3/output.txt", "Run3/Single/10%");
   run.add_data(3, 150, "../output/run4/output.txt", "Run4/Multi/10%");
   run.plot();
}
void run2()
{
   Run run(2, 0.01);
   run.add_data(0, 5,   "../output/run5/output.txt", "Run5/Single/0%");
   run.add_data(1, 5,   "../output/run6/output.txt", "Run6/Multi/0%");
   run.add_data(2, 100, "../output/run7/output.txt", "Run7/Single/10%");
   run.add_data(3, 100, "../output/run8/output.txt", "Run8/Multi/10%");
   run.plot();
}
void run3()
{
   Run run(3, 0.005);
   run.add_data(0, 5, "../output/run9/output.txt",   "Run9/Single/0%");
   run.add_data(1, 5, "../output/run10/output.txt",  "Run10/Multi/0%");
   run.add_data(2, 20, "../output/run11/output.txt", "Run11/Single/10%");
   run.add_data(3, 20, "../output/run12/output.txt", "Run12/Multi/10%");
   run.plot();
}
void run4()
{
   Run run(4, 0.001);
   run.add_data(0, 5, "../output/run13/output.txt", "Run13/Single/0%");
   run.add_data(1, 5, "../output/run14/output.txt", "Run14/Multi/0%");
   run.add_data(2, 5, "../output/run15/output.txt", "Run15/Single/10%");
   run.add_data(3, 5, "../output/run16/output.txt", "Run16/Multi/10%");
   run.plot();
}
void all()
{
   run1();
   run2();
   run3();
   run4();
}
