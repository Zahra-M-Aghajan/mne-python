.. _changes_0_10:

Version 0.10 (2015-10-26)
-------------------------

Changelog
~~~~~~~~~

- Add support for generalized M-way repeated measures ANOVA for fully balanced designs with :func:`mne.stats.f_mway_rm` by `Denis Engemann`_

- Add epochs browser to interactively view and manipulate epochs with :func:`mne.viz.plot_epochs` by `Jaakko Leppakangas`_

- Speed up TF-MxNE inverse solver with block coordinate descent by `Daniel Strohmeier`_ and `Yousra Bekhti`_

- Speed up zero-phase overlap-add (default) filtering by a factor of up to 2 using linearity by `Ross Maddox`_ and `Eric Larson`_

- Add support for scaling and adjusting the number of channels/time per view by `Jaakko Leppakangas`_

- Add support to toggle the show/hide state of all sections with a single keypress ('t') in :class:`mne.Report` by `Mainak Jas`_

- Add support for BEM model creation :func:`mne.make_bem_model` by `Eric Larson`_

- Add support for BEM solution computation :func:`mne.make_bem_solution` by `Eric Larson`_

- Add ICA plotters for raw and epoch components by `Jaakko Leppakangas`_

- Add new object ``mne.decoding.TimeDecoding`` for decoding sensors' evoked response across time by `Jean-Remi King`_

- Add command ``mne freeview_bem_surfaces`` to quickly check BEM surfaces with Freeview by `Alex Gramfort`_.

- Add support for splitting epochs into multiple files in :func:`mne.Epochs.save` by `Mainak Jas`_ and `Alex Gramfort`_

- Add support for jointly resampling a raw object and event matrix to avoid issues with resampling status channels by `Marijn van Vliet`_

- Add new method :class:`mne.preprocessing.Xdawn` for denoising and decoding of ERP/ERF by `Alexandre Barachant`_

- Add support for plotting patterns/filters in :class:`mne.decoding.CSP` and :class:`mne.decoding.LinearModel` by `Romain Trachel`_

- Add new object :class:`mne.decoding.LinearModel` for decoding M/EEG data and interpreting coefficients of linear models with patterns attribute by `Romain Trachel`_ and `Alex Gramfort`_

- Add support to append new channels to an object from a list of other objects by `Chris Holdgraf`_

- Add interactive plotting of topomap from time-frequency representation by `Jaakko Leppakangas`_

- Add ``plot_topo`` method to ``Evoked`` object by `Jaakko Leppakangas`_

- Add fetcher :mod:`mne.datasets.brainstorm <mne.datasets>` for datasets used by Brainstorm in their tutorials by `Mainak Jas`_

- Add interactive plotting of single trials by right clicking on channel name in epochs browser by `Jaakko Leppakangas`_

- New logos and logo generation script by `Daniel McCloy`_

- Add ability to plot topomap with a "skirt" (channels outside of the head circle) by `Marijn van Vliet`_

- Add multiple options to ICA infomax and extended infomax algorithms (number of subgaussian components, computation of bias, iteration status printing), enabling equivalent computations to those performed by EEGLAB by `Jair Montoya Martinez`_

- Add :func:`mne.Epochs.apply_baseline` method to ``Epochs`` objects by `Teon Brooks`_

- Add ``preload`` argument to :func:`mne.read_epochs` to enable on-demand reads from disk by `Eric Larson`_

- Big rewrite of simulation module by `Yousra Bekhti`_, `Mark Wronkiewicz`_, `Eric Larson`_ and `Alex Gramfort`_. Allows to simulate raw with artifacts (ECG, EOG) and evoked data, exploiting the forward solution. See :func:`mne.simulation.simulate_raw`, :func:`mne.simulation.simulate_evoked` and :func:`mne.simulation.simulate_sparse_stc`

- Add :func:`mne.Epochs.load_data` method to :class:`mne.Epochs` by `Teon Brooks`_

- Add support for drawing topomaps by selecting an area in :func:`mne.Evoked.plot` by `Jaakko Leppakangas`_

- Add support for finding peaks in evoked data in :func:`mne.Evoked.plot_topomap` by `Jona Sassenhagen`_ and `Jaakko Leppakangas`_

- Add source space morphing in :func:`morph_source_spaces` and :func:`SourceEstimate.to_original_src` by `Eric Larson`_ and `Denis Engemann`_

- Adapt ``corrmap`` function (Viola et al. 2009) to semi-automatically detect similar ICs across data sets by `Jona Sassenhagen`_ and `Denis Engemann`_ and `Eric Larson`_

- Clarify docstring for :class:`mne.preprocessing.ICA` by `jeythekey`_

- New ``mne flash_bem`` command to compute BEM surfaces from Flash MRI images by `Lorenzo Desantis`_, `Alex Gramfort`_ and `Eric Larson`_. See :func:`mne.bem.make_flash_bem`.

- New gfp parameter in :func:`mne.Evoked.plot` method to display Global Field Power (GFP) by `Eric Larson`_.

- Add :meth:`mne.Report.add_slider_to_section` methods to :class:`mne.Report` by `Teon Brooks`_

BUG
~~~

- Fix ``mne.io.add_reference_channels`` not setting ``info[nchan]`` correctly by `Federico Raimondo`_

- Fix ``mne.stats.bonferroni_correction`` reject mask output to use corrected p-values by `Denis Engemann`_

- Fix FFT filter artifacts when using short windows in overlap-add by `Eric Larson`_

- Fix picking channels from forward operator could return a channel ordering different from ``info['chs']`` by `Chris Bailey`_

- Fix dropping of events after downsampling stim channels by `Marijn van Vliet`_

- Fix scaling in :func:``mne.viz.utils._setup_vmin_vmax`` by `Jaakko Leppakangas`_

- Fix order of component selection in :class:`mne.decoding.CSP` by `Clemens Brunner`_

API
~~~

- Rename and deprecate ``mne.viz.plot_topo`` for ``mne.viz.plot_evoked_topo`` by `Jaakko Leppakangas`_

- Deprecated ``mne.decoding.transformer.ConcatenateChannels`` and replaced by ``mne.decoding.EpochsVectorizer`` by `Romain Trachel`_

- Deprecated ``lws`` and renamed ``ledoit_wolf`` for the ``reg`` argument in :class:`mne.decoding.CSP` by `Romain Trachel`_

- Redesigned and rewrote :meth:`mne.Epochs.plot` (no backwards compatibility) during the GSOC 2015 by `Jaakko Leppakangas`_, `Mainak Jas`_, `Federico Raimondo`_ and `Denis Engemann`_

- Deprecated and renamed ``mne.viz.plot_image_epochs`` for ``mne.plot.plot_epochs_image`` by `Teon Brooks`_

- ``picks`` argument has been added to :func:`mne.time_frequency.tfr_morlet`, :func:`mne.time_frequency.tfr_multitaper` by `Teon Brooks`_

- ``mne.io.Raw.preload_data`` has been deprecated for :func:`mne.io.Raw.load_data` by `Teon Brooks`_

- ``RawBrainVision`` objects now always have event channel ``'STI 014'``, and recordings with no events will have this channel set to zero by `Eric Larson`_

Authors
~~~~~~~

The committer list for this release is the following (preceded by number of commits):

* 273  Eric Larson
* 270  Jaakko Leppakangas
* 194  Alexandre Gramfort
* 128  Denis A. Engemann
* 114  Jona Sassenhagen
* 107  Mark Wronkiewicz
*  97  Teon Brooks
*  81  Lorenzo De Santis
*  55  Yousra Bekhti
*  54  Jean-Remi King
*  48  Romain Trachel
*  45  Mainak Jas
*  40  Alexandre Barachant
*  32  Marijn van Vliet
*  26  Jair Montoya
*  22  Chris Holdgraf
*  16  Christopher J. Bailey
*   7  Christian Brodbeck
*   5  Natalie Klein
*   5  Fede Raimondo
*   5  Alan Leggitt
*   5  Roan LaPlante
*   5  Ross Maddox
*   4  Dan G. Wakeman
*   3  Daniel McCloy
*   3  Daniel Strohmeier
*   1  Jussi Nurminen
