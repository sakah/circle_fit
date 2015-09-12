#include "TFile.h"
#include "TTree.h"
class Run
{
   public:
      Run(int irun, char* setup)
      {
         read_setup(irun, setup);

         char* data = Form("../output/run%d/output.txt", irun);
         read(data);
         set_alias();
      };

      TTree *t;
      double max_chi2;
      char title[32];
      char turn_type[32];
      char noise_occupancy[32];
      double diff_threshold;

   private:
      void set_alias()
      {
         t->SetAlias("dz", "(zfit-zhit)");
         t->SetAlias("dpt", "(ptfit-pthit)");
         t->SetAlias("dpz", "(pzfit-pzhit)");
         t->SetAlias("ptres", "(ptfit-pthit)/pthit");
         t->SetAlias("pzres", "(pzfit-pzhit)/pzhit");
         t->SetAlias("redchi2", "chi2/(num-5)");
      };

      void read(char* txt)
      {
         t = new TTree("t","t");
         t->SetMarkerStyle(20);
         //t->ReadFile(txt,"iev/I:maxLayer:sig1:sig1in:sig1out:in1:in1sig:in1noise:sig2:sig2in:sig2out:in2:in2sig:in2noise:num:dr/D:deg:zhit:zfit:pthit:ptfit:pzhit:pzfit:rad0:chi2");
         t->ReadFile(txt,"iev/I:mc_z/D:mc_pt:mc_pz:dx:dy:dr:deg1:deg2");
      };

      void read_setup(int irun, char* txt)
      {
         FILE* fp = fopen(txt,"r");
         if (fp==NULL) {
            fprintf(stderr,"ERROR: faield to open setup file %s\n", txt);
            return;
         }
         char line[128];
         int run_num;
         char type[32];
         char noise[32];
         double threshold;
         double maxchi2;

         while(fgets(line,sizeof(line),fp)) {
            sscanf(line, "%d %s %s %lf %lf",&run_num,type,noise,&threshold,&maxchi2);
            if (irun==run_num) {
               strcpy(turn_type,type);
               strcpy(noise_occupancy,noise);
               diff_threshold = threshold;
               max_chi2 = maxchi2;

               sprintf(title, "Run%d/%s/%s/%5.4f", run_num,type,noise,threshold);
            }
         }
         fclose(fp);
      };
};
