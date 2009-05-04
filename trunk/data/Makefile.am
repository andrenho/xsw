# Source file covered by the GNU Public License v3 
# See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/>

nobase_dist_pkgdata_DATA = tutorial/*
EXTRA_DIST = install-fonts

# Install fonts, if they're not installed
install-data-hook:
	./install-fonts $(datadir)

# Uninstall fonts
uninstall-hook:
	rm -rf $(datadir)/xsw/*.ttf
