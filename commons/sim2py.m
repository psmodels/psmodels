file_name = 'hola.csv'
flds = fields(simout);
aux = size(flds);
N = aux(1);

OUT = [];
header = [];
for it = 1:N
    fld = getfield(simout,flds{it});
    if it == 1
      OUT = fld.Time;  
      header = ['t'];
    end
    
    disp(flds{it});
    
    N_row_col = size(fld.Data);
    if N_row_col(2)>1
        for it_col = 1:N_row_col(2)
           header = strcat(header,',',flds{it},'_',string(it_col)) ;  
        end
    else
        header = strcat(header,',', flds{it});           
    end
    OUT = [OUT, fld.Data] ;
    
end


%write header to file
fid = fopen(file_name,'w'); 
fprintf(fid,'%s\n',header);
fclose(fid);
%write data to end of file
dlmwrite(file_name,OUT,'-append');
