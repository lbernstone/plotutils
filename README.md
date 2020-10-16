# plotutils

esp32: This library will use PSRAM if you have it.  Otherwise, you will probably not be able to work with images larger than ~140x140

This is release 2.6 of the GNU plotutils (plotting utilities) package,
including release 4.4 of GNU libplot: a thread-safe function library for
exporting two-dimensional vector graphics files, and for displaying
animated vector graphics under the X Window System.  The Web page for the
package is http://www.gnu.org/software/plotutils/plotutils.html .

In the top-level source directory, the file INSTALL contains generic
instructions for installing a GNU package, and the file INSTALL.pkg
contains package-specific instructions.  Please read them _in full_,
as well as this file, before attempting to install the package.

Also in the top-level source directory, the file COMPAT contains release
notes, and comments on compatibility with previous versions.  The file
PROBLEMS is worth looking at too.

Please send bug reports to <bug-plotutils@gnu.org>, and suggestions for
longer-range improvements to both <bug-plotutils@gnu.org> and the principal
author and current maintainer, Robert Maier <rsm@math.arizona.edu>.

NOTE: Neither the `pic2plot' program nor the `libplotter' C++ class library
is built by default, since they require a working C++ compiler.  But it is
easy to request that they be built.  For details, see INSTALL.pkg.  Also, a
standalone version of the `libxmi' scan-conversion library isn't built by
default, since `libxmi' is distributed as a separate package.

----------------------------------------------------------------------

The contents of the plotutils package are:

1. libplot.     This is the function library for device-independent
		two-dimensional vector graphics that the sample
		command-line programs `graph', `plot', `pic2plot',
		`tek2plot', and `plotfont' (see below) are based on.
		On platforms that support shared libraries, it is
		installed as a shared library.

		If you are a programmer, you may use this library yourself,
		to export vector graphics in many different file formats.
		You may also use it to create vector graphics animations
		under the X Window System.
		
		There are two versions of libplot: a conventional library
		of C functions, which is also referred to as libplot, and
		its C++ counterpart `libplotter', which is a class library.
		The latter is more convenient to use if you are programming
		in C++.  You must request at installation time that
		`libplotter' be built and installed, since it is not done
		automatically.  (See ./INSTALL.pkg.)  When we refer to
		`libplot', by default we mean both the C and the C++ versions.

		libplot includes functions to draw objects of many types:
		lines and polylines, circles and ellipses, circular and
		elliptic arcs, quadratic and cubic Bezier curves, and
		marker symbols.  Postscript-style `paths', made up of many
		segments, may be drawn.  There is support for color (both
		pen color and fill color for objects).

		Output formats include X11, PNG, PNM (i.e. PBM/PGM/PPM),
		pseudo-GIF, SVG, Adobe Illustrator, Postscript and
		Encapsulated Postscript (editable with the idraw drawing
		editor), CGM (by default, binary version-3 CGM output that
		complies with the WebCGM profile for Web-based vector
		graphics), Fig (editable with the xfig drawing editor), PCL
		5, HP-GL and HP-GL/2, Regis, Tektronix, and GNU metafile
		format.  GNU metafile format may be translated into any of
		the other formats with the `plot' utility (see below).

		NOTE: pseudo-GIF format is not the same as GIF format,
		since it does not use the LZW coding scheme.  So it does
		not transgress the well known Unisys LZW patent.  However,
		applications that can read GIF files should be able to read
		pseudo-GIF files.  libplot can also create animated
		pseudo-GIFs.

		libplot includes extensive support for accurate sizing and
		positioning of text.  This includes the placement of
		subscripts and superscripts.  Its X11, SVG, Illustrator,
		Postscript, CGM, and Fig drivers all support the 35
		standard Postscript fonts, and its PCL 5 and HP-GL/2
		drivers support the 45 standard LaserJet fonts.  In
		addition, all of these, together with the other (bitmap)
		drivers, support a set of 22 Hershey vector fonts.  The
		Hershey fonts include HersheyCyrillic and HersheyEUC (for
		Japanese).  Note that the Hershey fonts are not
		anti-aliased, so they will look much better in vector
		output, than in bitmap output.

		All supported fonts may be arbitrarily rotated and scaled.
		All fonts, except for symbol and dingbat fonts, and the
		Hershey Cyrillic and Japanese fonts, use the ISO-Latin-1
		encoding (a superset of ASCII; the ISO-Latin-1 support in
		the 20 non-Cyrillic, non-Japanese Hershey fonts is
		extensive but not quite complete).
		
		(Clones of the 35 standard Postscript fonts, in Type 1
		format, have been contributed by URW GmbH for distribution
		under the GNU General Public License.  They may well be
		available on your system, already.  If not, you may use the
		versions distributed with this package.  Installation
		instructions are in the file ./INSTALL.fonts.  Instructions
		for obtaining and installing Type 1 versions of the 45
		standard LaserJet fonts are included as well.)

		Similarly to Postscript, libplot has the nice feature that
		user coordinates (in terms of which you express the
		location of graphical objects) may be transformed to device
		coordinates by an arbitrary affine transformation.  A stack
		of drawing states (i.e., graphics contexts) is supported too.

2. libxmi.  This is a function library for drawing X11-style vector
		graphics (lines, polylines, polygons, circular and elliptic
		arcs) on an in-memory bitmap.  It is small, but powerful:
		it contains a modernized version of the scan conversion
		code contained in most X11 servers, which was written in
		the mid-to-late 1980's by programmers associated with the
		X Consortium.  It is built and installed only if you specify
		the `--enable-libxmi' option to ./configure.  The public
		header file for libxmi, xmi.h, will also be installed, as
		will the documentation (in texinfo format).
		
		The reason `libxmi' isn't built by default is that it's
		also distributed as a separate package.  Actually, what
		isn't built by default is a standalone version of libxmi.
		libplot/libplotter always contains an internal libxmi
		module, which helps it produce output in bitmap formats.

3. Sample command-line programs based on libplot, including the following.

	graph.  A full-featured scientific plotting program for plotting
		XY (i.e. 2-dimensional) data.  It plots a stream of
		datapoints, in real time if possible.  There is a
		well-chosen set of command-line options for adjusting the
		visual appearance of the plot, labelling axes (with
		expressions that may include subscripts and superscripts,
		and mathematical symbols), choosing marker symbols from
		various fonts, etc.  Multiplotting is supported (a plot may
		include sub-plots, side-by-side or inset).  Filled regions
		are also supported.

		Unlike the well-known plotting program `gnuplot', `graph'
		is device-independent in the sense that its options do not
		depend on the display device the plot is destined for.
		To the maximum degree feasible, the output of `graph' will
		appear the same on all display devices.  
	
		Which display device is driven, or output format is
		produced, is specified by the `-T' option.  There are
		effectively many different variants of `graph',
		distinguished by the intended display device.

		graph -T X      A variant that pops up an X window on an X
				display, and draws the plot in it.  It is
				most useful on modern (X11R6) displays,
				which can rotate and scale text
				arbitrarily.  It uses the 35 standard
				Postscript fonts.

		graph -T png    A variant that produces output in PNG
				(Portable Network Graphics) format.  Output
				in this format can be viewed with the free
				image display application `xv'.

		graph -T pnm	A variant that produces output in 
				`Portable Anymap' format (PBM/PGM/PPM,
				whichever is appropriate).  Output
				in this format can be viewed with `xv',
                                or translated to other formats with the
				`netpbm' package.

		graph -T gif	A variant that produces output in a
				pseudo-GIF format that can be displayed
				by many applications that understand	
				GIF format.  The pseudo-GIF format uses
				run-length encoding, so it does not
				transgress the well known Unisys LZW
				patent.

		graph -T svg    A variant that produces output in SVG
		                (scalable vector graphics) format.  SVG is
		                the XML-based graphics format that
                                has been endorsed by the W3 Consortium
				for Web use.  See 
				http://www.w3.org/Graphics .
				For comments on compatibility with other
				software that can edit or display
				SVG files, see the file ./COMPAT.

		graph -T ai	A variant that produces output in a
				format that can be viewed or edited
				with Adobe Illustrator.

		graph -T ps	A variant that produces EPS (encapsulated
				Postscript) output, which can be printed,
				displayed, or encapsulated in other
				documents.  Any standard page size is
				supported (letter, legal, ANSI sizes, ISO
				sizes such as a4 and a3, etc.)  The EPS
				output includes annotations that permit it
				to be edited with the freeware `idraw'
				drawing editor, or its successor
				`drawtool'.  See http://www.vectaport.com .

		graph -T cgm 	A variant that produces CGM vector graphics
				files (Computer Graphics Metafiles, as
				defined by ISO 8632:1992).  By default, its
				output files are binary version-3 CGM files
				that conform to the WebCGM profile for
				Web-based vector graphics (for WebCGM info,
				see http://www.cgmopen.org/ ).

		graph -T fig	A variant that produces a plot that
				the freeware `xfig' drawing editor can
				edit.  xfig can export the plot in numerous
				formats, such as GIF, X11 bitmap, and EPS.
				See http://duke.usask.ca/~macphed/soft/fig .

		graph -T pcl    A variant that produces a plot in PCL 5
				format, which is a sophisticated version of
				Hewlett-Packard's Printer Control Language.
				You may send the plot to a non-Postscript
				LaserJet or a high-end inkjet.  (Most
				inkjets do not support PCL 5.)  This
				variant supports the 45 standard PCL 5
				fonts that are built into many
				non-Postscript printers, such as LaserJets.

		graph -T hpgl	A variant that produces HP-GL (or by
				default, HP-GL/2) output.  HP-GL is the
				Hewlett-Packard Graphics Language, and may
				be printed out or plotted on a
				Hewlett-Packard LaserJet printer or
				plotter.  Also many applications, e.g. CAD
				applications, can import HP-GL or HP-GL/2
				figures.  This variant supports the 45
				standard PCL 5 fonts that are built into
				many non-Postscript printers, such as
				LaserJets.

		graph -T regis  A variant that produces ReGIS graphics 
				output, suitable for viewing on a
				DECwindows dxterm or a DEC graphics
				terminal, such as a VT340, VT330, VT241, or
				VT240.  (This variant lacks the Postscript
				fonts of the other variants though, like
				them, it has a complete set of vector
				Hershey fonts.)

		graph -T tek	A variant that produces Tektronix output,
				suitable for viewing, e.g., on an X Windows
				xterm or an MS-DOS kermit doing Tektronix
				emulation.  (This variant lacks the
				Postscript fonts of the other variants
				though, like them, it has a complete set of
				vector Hershey fonts.  Also, it does not
				support filling of regions.)

		graph		The `raw' variant, which produces output in
				GNU graphics metafile format.  This is an
				enhanced version of the traditional plot(5)
				format found on some operating systems.
				The `plot' program (see below) must be used
				to convert this to another format, or to
				drive a display device.

		Of these variants, `graph -T X', `graph -T tek', and raw
		`graph' are real-time.  That means that under some
		circumstances, they act as filters: they read data points
		from standard input, and plot them as they are read.  For
		this to happen, the abscissa and ordinate ranges of the
		plot must be specified on the command line.  (E.g., the
		user would do

			program | graph -T X -x xmin xmax -y ymin ymax

		where `program' generates a stream of data points.)
		
		All variants of `graph' will accept ASCII input (the
		default), or unformatted binary input (i.e., a stream of
		floating point numbers or integers), or input in the
		`table' format produced by the program `gnuplot' (which you
		may select by specifying the `-I g' option).  Gnuplot will
		produce table-format output if you do `set terminal table';
		you can pipe gnuplot's output to any of the variants of
		graph by using the gnuplot `set output' command.  If you
		are piping to `graph -T X', by repeatedly using the gnuplot
		`set output' command you may easily produce an arbitrarily
		large number of plots in different X windows, each in a
		different style.

	plot.   This is a so-called plot filter, which takes a stream in GNU
		graphics metafile format, and either translates it to
		another format or uses it to drive a display device.

		Since this distribution includes `graph -T X', `graph -T
		png', `graph -T pnm', `graph -T gif', `graph -T svg',
		`graph -T ai', `graph -T ps', `graph -T cgm', `graph -T
		fig', `graph -T pcl', `graph -T hpgl', `graph -T regis',
		and `graph -T tek', all of which can drive display devices
		directly, `plot' is only occasionally useful.  It may be
		used, though, to produce graphical output in more than one
		format at once.  To do this, you would pipe the output of a
		datapoint-generating program to the raw variant of `graph',
		and then use the `tee' command to direct the output of raw
		`graph', which is in metafile format, to two separate
		invocations of `plot'.
	
		`plot' may also be useful as a post-processor for older
		programs that produce output in the traditional plot(5)
		graphics format.  GNU metafile format is an enhanced version
		of plot(5) format.

	pic2plot.  This is a utility program that takes a file in the pic
		language, and either translates it to another format or
		displays it on an X display.  The pic language, which was
		developed at Bell Laboratories, is used for creating
		box-and-arrow diagrams of the kind frequently found in
		technical papers and textbooks.  It was originally
		introduced as a feature of the Bell Labs `troff'
		text-processing software.

		You must request at installation time that pic2plot be
		built and installed, since it is not done automatically.
		(See ./INSTALL.pkg.)

		pic2plot is largely compatible with `gpic', the GNU
		implementation of the pic-to-troff translator.  However,
		since it is built on top of libplot, it supports some new
		features.  It supports all the output formats that libplot
		supports: X11, PNG, PNM, GIF, SVG, AI, PS, WebCGM, Fig,
		PCL, HP-GL, Tek, and Metafile.

	tek2plot.  This is a utility program that emulates a Tektronix 4014
		terminal in the sense that it reads a stream of Tektronix
		commands, and either produces an output file in another
		format or displays the corresponding graphics on an X
		display.  An output file in any of the graphics file
		formats that libplot support can be produced.

		tek2plot is useful if you have a legacy program that was
		designed to drive a Tektronix terminal or emulator, or if
		you have files in Tektronix format that need to be
		translated to a modern format, or edited.

		The directory ./tek2plot/teksamples includes a few files in
		Tektronix format that you may experiment with.  You may
		also experiment by piping the output of `gnuplot', if you
		have configured it to produce Tektronix-format plots, to
		these filters (the gnuplot terminal types `kc_tek40xx',
		`km_tek40xx', `tek40xx', and `vttek' all work).  tek2plot
		does an excellent job of emulating the non-interactive
		features of a Tektronix 4014, and although it does not
		support all the features supported by the Tektronix
		emulator in the MS-DOS version of kermit, it can certainly
		parse the output of the gnuplot Tektronix terminal drivers.
		
	plotfont. This is a simple utility that prints out a character
		chart for any font available to the above four utilities
		(graph, plot, pic2plot, tek2plot) and the underlying
		libplot library.  All output formats are supported.  Which
		fonts are available depends on the `-T' option that is
		specified, i.e., on the output format.

	hersheydemo.  This is a demo program for the Hershey vector fonts,
		as implemented in the libplot library.  It outputs a demo
		page, designed by Dr. Hershey himself.  The page is taken
		from his 1972 article "A computer system for scientific
		typography", published in Computer Graphics and Image
		Processing (vol. 1, no. 4, pp. 373-385).

		Note that the Hershey vector fonts look much better in
		vector output formats, than they do in bitmap formats.
		That is because libplot does not currently do anti-aliasing
		of fonts (or more accurately the libxmi rasterization
		library, which it relies on, does not).  You would do
		`hersheydemo -T ps > demo.ps' to produce PS output,
		`hersheydemo -T svg > demo.svg' to produce SVG output, etc.

4. Command-line mathematical programs not based on libplot, including the
   following.

	spline. This program does spline interpolation of input data, which
		may be of arbitrary dimensionality.  That is, it takes a
		file of datapoints, and interpolates between them to
		produce an interpolated segment of the input data.  It acts
		as a filter, though usually not as a real-time one (in the
		most common mode of operation, the entire input must be
		read before any data points are output).

		The output spline is normally a cubic spline, but if a
		`tension' parameter is set to a nonzero value, the output
		spline will be a so-called spline under tension.  There is
		also support for doing cubic Bessel interpolation.  If this
		option is selected, `spline' acts as a true real-time
		filter, since cubic Bessel interpolation is local rather
		than global.
		
	ode.  This interactive program supplements the computation engine
		of `gnuplot', which will compute and plot functions, by
		providing the ability to integrate systems of ordinary
		differential equations (ODE's).  ode will solve the initial
		value problem for one or more first-order ODE's, when
		provided with an explicit expression for each equation.
		ode parses the set of equations and the set of initial
		conditions, which may be typed in manually or read from a
		file, and then produces a stream of data points that may be
		piped to any of the variants of `graph'.  If a real-time
		variant of `graph' (e.g. `graph -T X' or `graph -T tek') is
		used, the numerical solution will be displayed in real
		time, as it is generated.

		One application (certainly not the only one!) of ode is to
		graph the indefinite integrals of the sorts of function
		that gnuplot can graph.  All the primitive real-valued
		functions that are built into gnuplot are built into ode.

		A directory of sample ode input files is installed (usually
		as /usr/local/share/ode or /usr/share/ode) as part of the
		package.

	double. This is a filter for converting, scaling and cutting
		unformatted (binary) or ASCII data streams.  It is still
		under development and is not yet documented.
