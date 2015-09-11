def make_script(irun)
   body = <<-"END"
#!/bin/bash
/home/had/hideyuki/private/genfit2/KEKCC/circle_fit/run.sh #{irun}
   END
end

(1..32).each do |irun|
   fname="tmp/irun-#{irun}.sh"
   body = make_script(irun)
   File.open(fname,"w") do |f|
      f.write body
   end
   File.chmod(0755, fname)
end
