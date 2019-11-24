program HelloWorld;
const
message = 'This is my message';

var
a, b, s: integer;

begin
    writeln('Nhap vao so a: ');
    readln (a);
    writeln('Nhap vao so b: ');
    readln (b);
    s := (a + b);
    writeln;
    writeln('Tong a + b = ', s);
end.