

C = repmat('A',[1,1e8]);
shmkey='SHM_TEST';

X=sharedmatrix('import',shmkey, C);


%X=sharedmatrix('attach',shmkey);

for i = 1:1e8 
    X(i) = X(i) + i;
    pause(1e-6);
end

X
 
% do something with X
%sharedmatrix('detach',shmkey,X);

%sharedmatrix('free',shmkey);