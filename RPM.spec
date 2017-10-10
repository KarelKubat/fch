Summary: Interactive file contents changer
Name: fch
Version: 2.02
Release: 1
Copyright: e-tunity
Group: Applications/Productivity
Buildroot: /tmp/fch
Provides: e-tunity:fch
Requires: e-tunity:e-lib

%description
This is the "fch" package, a small program that lets you change file
contents interactively. You specify a searchstring and a replacement
string on the commandline, and fch will examine files and let you
change the contents, or skip the suggested replacement, and so on.

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/e/bin $RPM_BUILD_ROOT/usr/e/doc
export EBASE=$RPM_BUILD_ROOT/usr/e
export EBINDIR=$RPM_BUILD_ROOT/usr/e/bin
make -C /usr/e/src/e/fch install
make -C /usr/e/src/e/fch installdoc
find /tmp/fch/usr/e -type f | \
    sed 's:/tmp/fch::' | \
    sort > /usr/e/src/e/fch/rpm.filelist

%post
echo Package fch was installed. Please make sure that you:
echo 1. have /usr/e/bin in your PATH setting
echo 2. read /usr/e/doc/fch.README for instructions.
echo To see how fch works, just invoke it without arguments to see the
echo usage information.

%clean
rm -rf $RPM_BUILD_ROOT

%files -f /usr/e/src/e/fch/rpm.filelist
%defattr(-,e,users)
