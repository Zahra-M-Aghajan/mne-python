.. NOTE: we are now using links to highlight new functions and classes.
   Please follow the examples below like :func:`mne.stats.f_mway_rm`, so the
   whats_new page will have a link to the function/class documentation.

.. NOTE: there are 3 separate sections for changes, based on type:
   - "Enhancements" for new features
   - "Bugs" for bug fixes
   - "API changes" for backward-incompatible changes

.. _changes_0_21:

Version 0.21 (2020-09-21)
-------------------------

.. |Rahul Nadkarni| replace:: **Rahul Nadkarni**
.. |Lau Møller Andersen| replace:: **Lau Møller Andersen**
.. |Kyle Mathewson| replace:: **Kyle Mathewson**
.. |Jan Sedivy| replace:: **Jan Sedivy**
.. |Johann Benerradi| replace:: **Johann Benerradi**
.. |Martin Schulz| replace:: **Martin Schulz**
.. |Jeroen Van Der Donckt| replace:: **Jeroen Van Der Donckt**
.. |Simeon Wong| replace:: **Simeon Wong**
.. |Svea Marie Meyer| replace:: **Svea Marie Meyer**
.. |Lx37| replace:: **Lx37**
.. |Liberty Hamilton| replace:: **Liberty Hamilton**
.. |Steven Bierer| replace:: **Steven Bierer**

Enhancements
~~~~~~~~~~~~

- Modified :meth:`mne.Epochs.pick_types` to remove dropped channel types from ``reject`` and ``flat`` dictionaries **by new contributor** |Rahul Nadkarni|_

- Add function :func:`mne.preprocessing.regress_artifact` to remove artifacts using linear regression **by new contributor** |Kyle Mathewson|_ and `Eric Larson`_

- Add ``sources`` and ``detectors`` options for fNIRS use of :meth:`mne.viz.plot_alignment` allowing plotting of optode locations in addition to channel midpoint ``channels`` and ``path`` between fNIRS optodes **by new contributor** |Kyle Mathewson|_

- BrainVision data format files are now parsed for EEG impedance values in :func:`mne.io.read_raw_brainvision` and provided as a ``.impedances`` attribute of ``raw`` **by new contributor** |Jan Sedivy|_ and `Stefan Appelhoff`_

- Add function :func:`mne.channels.combine_channels` to combine channels from Raw, Epochs, or Evoked according to ROIs (combinations including mean, median, or standard deviation; can also use a callable) **by new contributor** |Johann Benerradi|_

- Improved documentation building instructions and execution on Windows **by new contributor** |Martin Schulz|_, `kalenkovich`_, and `Eric Larson`_

- Speed up reading of annotations in EDF+ files **by new contributor** |Jeroen Van Der Donckt|_

- Add head to mri and mri to voxel space transform details to :ref:`plot_source_alignment` tutorial, by `Alex Rockhill`_

- Improve memory efficiency of :func:`mne.concatenate_epochs` by `Eric Larson`_

- Allow picking channels in raw instances (e.g., :meth:`mne.io.Raw.pick_types`) without preloading data, by `Eric Larson`_

- :meth:`mne.preprocessing.ICA.plot_sources` now plots annotation markers similar to :meth:`mne.io.Raw.plot` by `Luke Bloy`_

- Add support for scalar multiplication and division of :class:`mne.time_frequency.AverageTFR` instances by `Luke Bloy`_

- Add support for signals in mV for :func:`mne.io.read_raw_brainvision` by `Clemens Brunner`_

- :meth:`mne.Epochs.plot_psd_topomap` and :func:`mne.viz.plot_epochs_psd_topomap` now allow joint colorbar limits across subplots, by `Daniel McCloy`_.

- Add support for using loose-orientation surface priors with free-orientation volume priors in mixed source space inverses by `Eric Larson`_

- Add :class:`mne.MixedVectorSourceEstimate` for vector source estimates for mixed source spaces, by `Eric Larson`_

- Add mixed and volumetric source estimate plotting using volumetric ray-casting to :meth:`mne.MixedSourceEstimate.plot` and :meth:`mne.VolSourceEstimate.plot_3d` by `Eric Larson`_

- Add :meth:`mne.MixedSourceEstimate.surface` and :meth:`mne.MixedSourceEstimate.volume` methods to allow surface and volume extraction by `Eric Larson`_

- Add :meth:`mne.VectorSourceEstimate.project` to project vector source estimates onto the direction of maximum source power by `Eric Larson`_

- Add support to :func:`mne.extract_label_time_course` for vector-valued and volumetric source estimates by `Eric Larson`_

- Add method :meth:`mne.VolSourceEstimate.in_label` by `Eric Larson`_

- Add support for mixed source spaces to :func:`mne.compute_source_morph` by `Eric Larson`_

- Add support for volume and mixed source spaces to :func:`mne.stats.summarize_clusters_stc` by `Eric Larson`_

- Add support for omitting the SDR step in volumetric morphing by passing ``n_iter_sdr=()`` to `mne.compute_source_morph` by `Eric Larson`_

- Add ``single_volume`` argument to :func:`mne.setup_volume_source_space` to facilitate creating source spaces with many volumes (e.g., all subvolumes of ``aseg.mgz``) by `Eric Larson`_

- Add support for passing a string argument to ``bg_img`` in `mne.viz.plot_volume_source_estimates` by `Eric Larson`_

- Add support for providing the destination surface source space in the ``src_to`` argument of :func:`mne.compute_source_morph` by `Eric Larson`_

- Add explained variance logging to :func:`mne.inverse_sparse.mixed_norm`, :func:`mne.inverse_sparse.gamma_map`, and :func:`mne.beamformer.rap_music` by `Eric Larson`_

- Add ``tol_kind`` option to :func:`mne.compute_rank` by `Eric Larson`_

- Allow resampling raw data with :func:`mne.io.Raw.resample` without preloading data, by `Eric Larson`_

- Allow using ``pick_ori='vector'`` with a fixed-orientation inverse to facilitate visualization with :func:`mne.viz.plot_vector_source_estimates` by `Eric Larson`_

- :func:`mne.viz.plot_dipole_locations` and :meth:`mne.Dipole.plot_locations` gained a ``title`` argument to specify a custom figure title in ``orthoview`` mode by `Richard Höchenberger`_

- Add orientations projected onto the MRI slices in :func:`mne.viz.plot_dipole_locations` in ``'orthoview'`` mode by `Eric Larson`_

- Add temporal derivative distribution repair (TDDR) :func:`mne.preprocessing.nirs.temporal_derivative_distribution_repair` with shortened alias ``mne.preprocessing.nirs.tddr`` by `Robert Luke`_

- Add :func:`mne.read_freesurfer_lut` to make it easier to work with volume atlases by `Eric Larson`_

- Add support for overlap-add processing when ``method='spectrum_fit'`` in :func:`mne.io.Raw.notch_filter` by `Eric Larson`_

- Add functionality to interpolate bad NIRS channels by `Robert Luke`_

- Add ability to interpolate EEG channels using minimum-norm projection in :meth:`mne.io.Raw.interpolate_bads` and related functions with ``method=dict(eeg='MNE')`` by `Eric Larson`_

- Added ability of :func:`mne.io.read_raw_nirx` to open data by passing path to header file `Robert Luke`_

- Add :meth:`mne.channels.DigMontage.rename_channels` to allow renaming montage channels by `Eric Larson`_

- Document :meth:`mne.channels.compute_native_head_t` to allow computing the native-to-head transformation that will be applied when doing :meth:`raw.set_montage <mne.io.Raw.set_montage>` and related functions by `Eric Larson`_

- Add support to in :meth:`mne.io.Raw.plot` for passing ``clipping`` as a float to clip to a proportion of the dedicated channel range by `Eric Larson`_

- Add function :func:`mne.preprocessing.annotate_muscle_zscore` to annotate periods with muscle artifacts. by `Adonay Nunes`_

- Add :func:`mne.stats.ttest_ind_no_p` to mirror :func:`mne.stats.ttest_1samp_no_p` with hat correction by `Eric Larson`_

- Add `mne.stats.combine_adjacency` to combine adjacency matrices for independent data dimensions to enable things like spatio-temporal-time-frequency clustering in `mne.stats.permutation_cluster_test` by `Eric Larson`_

- Speed up raw data reading without preload in :func:`mne.io.read_raw_nirx` by `Eric Larson`_

- Speed up :meth:`mne.Epochs.copy` and :meth:`mne.Epochs.__getitem__` by avoiding copying immutable attributes by `Eric Larson`_

- Speed up and reduce memory usage of :meth:`mne.SourceEstimate.plot` and related functions/methods when ``show_traces=True`` by `Eric Larson`_

- Reduce memory usage of `~mne.io.Raw.plot_psd`, `~mne.time_frequency.psd_welch`, and `~mne.time_frequency.psd_array_welch` for long segments of data by `Eric Larson`_

- Support for saving movies of source time courses (STCs) with ``brain.save_movie`` method and from graphical user interface by `Guillaume Favelier`_

- Add ``mri`` and ``show_orientation`` arguments to :func:`mne.viz.plot_bem` by `Eric Larson`_

- Add :func:`mne.viz.centers_to_edges` to help when using :meth:`matplotlib.axes.Axes.pcolormesh` with flat shading by `Eric Larson`_

- Add ``on_missing='raise'`` to :meth:`mne.io.Raw.set_montage` and related functions to allow ignoring of missing electrode coordinates by `Adam Li`_

- Add ``on_missing='raise'`` to :func:`mne.viz.plot_events` to allow ignoring missing events when passing ``event_id`` by `Eric Larson`_

- Add REST EEG infinity reference scheme to :meth:`mne.io.Raw.set_eeg_reference` and related functions by `Eric Larson`_

- Add better sanity checking of ``max_pca_components`` and ``n_components`` to provide more informative error messages for :class:`mne.preprocessing.ICA` by `Eric Larson`_

- Add ``plot`` option to :meth:`mne.viz.plot_filter` allowing selection of which filter properties are plotted and added option for user to supply ``axes`` by `Robert Luke`_

- Add estimation method legend to :func:`mne.viz.plot_snr_estimate` by `Eric Larson`_

- Add support to `mne.SourceSpaces.export_volume` for ``mri_resolution='sparse'`` to color only the nearest-neighbor voxels instead of entire regions by `Eric Larson`_

- Add ``axes`` argument to :func:`mne.viz.plot_evoked_white`, :meth:`mne.Evoked.plot_white`, and :func:`mne.viz.plot_snr_estimate` by `Eric Larson`_

- Change default to ``surfaces='auto'`` from ``surfaces='head'`` to allow :func:`mne.viz.plot_alignment` to work when just passing a :class:`mne.Info` as ``plot_alignment(info)`` by `Eric Larson`_

- Add ECoG misc EDF dataset to the :ref:`tut-working-with-ecog` tutorial to show snapshots of time-frequency activity by `Adam Li`_

- Add :func:`mne.viz.set_3d_options` and ``MNE_3D_OPTION_ANTIALIAS`` environment variable to control full-scene antialiasing (FXAA) in 3D functions like :ref:`mne coreg`, :func:`mne.viz.plot_alignment`, and :func:`mne.viz.plot_source_estimates`; this can be useful on systems where FXAA does not work well, such as some with MESA software rendering, by `Eric Larson`_

- Add config variable ``MNE_TQDM`` to support explicitly setting the TQDM backend to use, for example ``tqdm`` or ``tqdm.auto`` (default) by `Eric Larson`_

- Add better support for reading corrupted FIF files in :func:`mne.io.read_raw_fif` by `Eric Larson`_

- BIDS conformity: When saving FIF files to disk and the files are split into parts, the ``split_naming='bids'`` parameter now uses a "_split-%d" naming instead of the previous "_part-%d", by `Stefan Appelhoff`_

- Add support for whitening and multiple channel types in :func:`mne.beamformer.make_dics` by `Marijn van Vliet`_

- Add better error message when trying to save incompatible `~mne.Evoked` objects to the same file by `Eric Larson`_

- Add support for loading complex numbers from mat files by `Thomas Hartmann`_

- Add generic reader function :func:`mne.io.read_raw` that loads files based on their extensions (it wraps the underlying specific ``read_raw_xxx`` functions) by `Clemens Brunner`_

- Add automatic T3 magnetometer detection and application of :meth:`mne.io.Raw.fix_mag_coil_types` to :func:`mne.preprocessing.maxwell_filter` by `Eric Larson`_

- Add extended SSS (eSSS) support to :func:`mne.preprocessing.maxwell_filter` by `Eric Larson`_

- Add ``'auto'`` option to :meth:`mne.preprocessing.ICA.find_bads_ecg` to automatically determine the threshold for CTPS method by `Yu-Han Luo`_

- Add a ``notebook`` 3d backend for visualization in jupyter notebook with :func:`mne.viz.set_3d_backend` by `Guillaume Favelier`_

- Add support for reading and writing surfaces in Wavefront .obj format to the :func:`mne.read_surface` and :func:`mne.write_surface` by `Marijn van Vliet`_

- Add tutorial on how to manually fix BEM meshes in Blender by `Marijn van Vliet`_ and `Ezequiel Mikulan`_

- :func:`mne.write_evokeds` will now accept :class:`mne.Evoked` objects with differing channel orders in ``info['bads']``, which would previously raise an exception by `Richard Höchenberger`_

- Add support for reading channel names (e.g., for Ricoh data) to :func:`mne.io.read_raw_kit` by `Alex Gramfort`_ and `Eric Larson`_

- The ``reject_tmin`` and ``reject_tmax`` parameters of :class:`mne.Epochs` are now taken into account when using the ``reject_by_annotation`` parameter by `Stefan Appelhoff`_

- :func:`mne.preprocessing.find_bad_channels_maxwell` now automatically applies a low-pass filter before running bad channel detection. This can be disabled, restoring previous behavior by `Richard Höchenberger`_

- Add ``proj='reconstruct'`` to :meth:`mne.Evoked.plot` and related functions to apply projectors and then undo the signal bias using field mapping by `Eric Larson`_

- Add writing BEM surfaces and solutions in H5 format in :func:`mne.write_bem_surfaces` and :func:`mne.write_bem_solution` by `Eric Larson`_

- When picking a subset of channels, or when dropping channels from `~mne.io.Raw`, `~mne.Epochs`, or `~mne.Evoked`, projectors that can only be applied to the removed channels will now be dropped automatically by `Richard Höchenberger`_

- :class:`mne.Report` now can add topomaps of SSP projectors to the generated report. This behavior can be toggled via the new ``projs`` argument by `Richard Höchenberger`_

- When passing a list of `~mne.Evoked` objects to `~mne.viz.plot_compare_evokeds`, each evoked's ``.comment`` attribute will be used to label the trace. If ``.comment`` is empty, a 1-based index is assigned as the label by  `Richard Höchenberger`_

- Speed up :func:`mne.stats.summarize_clusters_stc` using Numba by `Yu-Han Luo`_

- Add ``reject_by_annotation=True`` to :func:`mne.make_fixed_length_epochs` and :meth:`mne.preprocessing.ICA.plot_properties` to reject bad data segments based on annotation by `Yu-Han Luo`_

- `~mne.Report.parse_folder` now accepts a path-like folder name (it used to work with strings only) by `Alex Gramfort`_

- Add ``component_order`` parameter to :class:`mne.decoding.CSP` which allows switching between ``mutual_info`` (default) and ``alternate`` (a simpler and frequently used option) by `Martin Billinger`_ and `Clemens Brunner`_

- Add memory size information to the ``repr`` of :class:`mne.SourceSpaces` and :class:`mne.SourceEstimate` and related classes by `Eric Larson`_

- Add reader for Persyst (.lay + .dat format) data in :func:`mne.io.read_raw_persyst` by `Adam Li`_

- Use PyVista as the default backend for 3D visualization instead of Mayavi by `Guillaume Favelier`_

- Add reader for SNIRF NIRS data in :func:`mne.io.read_raw_snirf` by `Robert Luke`_

- `~mne.Evoked` has gained ``tmin`` and ``tmax`` attributes for more consistency with `~mne.Epochs` by `Richard Höchenberger`_

Bugs
~~~~

- Fix bug for writing and reading complex evoked data modifying :func:`mne.write_evokeds` and :func:`mne.read_evokeds` **by new contributor** |Lau Møller Andersen|_

- Fix bug by adding error message when trying to save complex stc data in a non.-h5 format :meth:`mne.VolSourceEstimate.save` **by new contributor** |Lau Møller Andersen|_

- Fix bug with logging in :meth:`mne.io.Raw.set_eeg_reference` and related functions **by new contributor** |Simeon Wong|_

- Fix bug with :func:`mne.io.read_raw_gdf` where birthdays were not parsed properly, leading to an error **by new contributor** |Svea Marie Meyer|_

- Fix bug with :func:`mne.io.read_raw_edf` where recording ID was not read properly for non-ASCII characters **by new contributor** |Lx37|_

- Fix bug in :func:`mne.set_eeg_reference` and related functions to set ``info['custom_ref_applied']`` to ``True`` for 'ecog' and 'seeg' channels in addition to 'eeg' **by new contributor** |Liberty Hamilton|_

- Fix bug with :func:`mne.chpi.compute_chpi_amplitudes` and :func:`mne.chpi.filter_chpi` to optimize time window length **by new contributor** |Steven Bierer|_

- Fix bug with :func:`mne.preprocessing.ICA.find_bads_eog` when more than one EOG components are present by `Christian O'Reilly`_

- Fix bug with non-preloaded data when using ``raw.apply_proj().load_data().get_data()`` where projectors were not applied by `Eric Larson`_

- Fix bug to permit :meth:`stc.project('nn', src) <mne.VectorSourceEstimate.project>` to be applied after ``stc`` was restricted to an :class:`mne.Label` by `Luke Bloy`_

- Fix bug with :func:`mne.io.Raw.set_meas_date` to support setting ``meas_date`` to ``None``, by `Luke Bloy`_

- Fix bug with :func:`mne.setup_volume_source_space` when ``volume_label`` was supplied where voxels slightly (in a worst case, about 37% times ``pos`` in distance) outside the voxel-grid-based bounds of regions were errantly included, by `Eric Larson`_

- Fix bug with :ref:`mne coreg` where reverse scalings were applied to ``src[0]['src_mri_t']`` for volume source spaces, so morphing and plotting did not work correctly by `Eric Larson`_

- Fix bug with :func:`mne.io.read_raw_ctf` when reference magnetometers have the compensation grade marked by `Eric Larson`_

- Fix bug with `mne.SourceSpaces.export_volume` with ``use_lut=False`` where no values were written by `Eric Larson`_

- Fix bug with :func:`mne.preprocessing.annotate_movement` where bad data segments, specified in ``raw.annotations``, would be handled incorrectly by `Luke Bloy`_

- Fix bug with :func:`mne.compute_source_morph` when more than one volume source space was present (e.g., when using labels) where only the first label would be interpolated when ``mri_resolution=True`` by `Eric Larson`_

- Fix bug with :func:`mne.compute_source_morph` when morphing to a volume source space when ``src_to`` is used and the destination subject is not ``fsaverage`` by `Eric Larson`_

- Fix bug with :func:`mne.compute_source_morph` where outermost voxels in the destination source space could be errantly omitted by `Eric Larson`_

- Fix bug with :func:`mne.compute_source_morph` where complex data was cast to real when doing a volumetric morph by `Eric Larson`_

- Fix bug with :func:`mne.minimum_norm.compute_source_psd_epochs` and :func:`mne.minimum_norm.source_band_induced_power` raised errors when ``method='eLORETA'`` by `Eric Larson`_

- Fix bug with :func:`mne.minimum_norm.apply_inverse` where the explained variance did not work for complex data by `Eric Larson`_

- Fix bug with :func:`mne.preprocessing.compute_current_source_density` where values were not properly computed; maps should now be more focal, by `Alex Rockhill`_ and `Eric Larson`_

- Fix bug with :func:`mne.combine_evoked` where equal-weighted averages were wrongly computed as equal-weighted sums, by `Daniel McCloy`_

- Fix bug with :meth:`mne.channels.DigMontage.plot` when reference channels with no defined position are present, by `Eric Larson`_

- Fix bug with :func:`mne.channels.read_custom_montage` where ``"headshape"`` points in SFP format were not read properly, by `Eric Larson`_

- Fix bug with setting HTML classes when using :meth:`mne.Report.add_bem_to_section` by `Eric Larson`_

- Fix bug with convex-hull based MEG helmet creation where the face area could be covered up, by `Eric Larson`_

- Fix bug with :func:`mne.inverse_sparse.mixed_norm` and :func:`mne.inverse_sparse.gamma_map` with ``return_as_dipoles=True`` and :func:`mne.beamformer.rap_music` where ``dip.gof`` was the same for all dipoles. GOF values / explained variance across all dipoles now gets split among the dipoles using SVD of the lead fields. To get the total GOF, ``sum(dip.gof for dip in dipoles)`` can be used, by `Eric Larson`_

- Fix bug with :func:`mne.inverse_sparse.gamma_map` where output data was not assigned properly when using a free-orientation forward and ``xyz_same_gamma=False`` by `Eric Larson`_

- Fix to enable interactive plotting with no colorbar with :func:`mne.viz.plot_evoked_topomap` by `Daniel McCloy`_

- Fix plotting with :func:`mne.viz.plot_evoked_topomap` to pre-existing axes by `Daniel McCloy`_

- Fix bug with :func:`mne.viz.plot_vector_source_estimates` using the PyVista backend with ``time_viewer=True`` when updating the arrow colormaps by `Eric Larson`_

- Fix bug with :func:`mne.viz.plot_vector_source_estimates` where ``clim='auto'`` and ``clim=dict(..., kind='percent')`` did not take into account the magnitude of the activation, by `Eric Larson`_

- The default plotting mode for :func:`mne.io.Raw.plot` and :ref:`mne browse_raw` has been changed to ``clipping=3.`` to facilitate data analysis with large deflections, by `Eric Larson`_

- PSD plots will now show non-data channels (e.g., ``misc``) if those channels are explicitly passed to ``picks``, by `Daniel McCloy`_.

- Fix bug with :func:`mne.time_frequency.read_tfrs` where ``info['meas_date']`` was not parsed correctly, by `Eric Larson`_

- Fix bug with :func:`mne.time_frequency.tfr_array_stockwell` where inputs were not properly validated by `Eric Larson`_

- Fix handling of NaN when using TFCE in clustering functions such as :func:`mne.stats.spatio_temporal_cluster_1samp_test` by `Eric Larson`_

- Fix handling of signs when using TFCE by `Eric Larson`_

- The :class:`mne.MixedSourceEstimate` class has been clarified to contain two cortical surface source spaces, plus at least one other source space. Creating source estimates in other orderings is not supported, by `Eric Larson`_

- Fix bug where :class:`VolSourceEstimate.vertices <mne.VolSourceEstimate>` was an instance of :class:`~numpy.ndarray` instead of :class:`python:list` of one :class:`~numpy.ndarray`, by `Eric Larson`_

- Fix default to be ``foreground=None`` in :func:`mne.viz.plot_source_estimates` to use white or black text based on the background color by `Eric Larson`_

- Fix bug with writing EGI and CTF `mne.Info` to H5 format, e.g., with `mne.time_frequency.AverageTFR.save` by `Eric Larson`_

- Fix bug with topomap outlines in :meth:`mne.time_frequency.AverageTFR.plot_joint` and :meth:`mne.time_frequency.AverageTFR.plot_topo` by `Eric Larson`_

- Fix bug with :func:`mne.io.Raw.plot` where toggling all projectors did not actually take effect by `Eric Larson`_

- Fix bug with :func:`mne.write_proj` where the number of columns was incorrectly written by `Eric Larson`_

- Fix bug with :func:`mne.read_epochs` when loading data in complex format with ``preload=False`` by `Eric Larson`_

- Fix bug with :meth:`mne.Epochs.save` where the file splitting calculations did not account for the sizes of non-data writes by `Eric Larson`_

- Fix bug with :class:`mne.Epochs` when metadata was not subselected properly when ``event_repeated='drop'`` by `Eric Larson`_

- Fix bug with :class:`mne.Epochs` where ``epochs.drop_log`` was a list of list of str rather than an immutable tuple of tuple of str (not meant to be changed by the user) by `Eric Larson`_

- Fix bug with :class:`mne.Report` where the BEM section could not be toggled by `Eric Larson`_

- Fix bug when using :meth:`mne.Epochs.crop` to exclude the baseline period would break :func:`mne.Epochs.save` / :func:`mne.read_epochs` round-trip by `Eric Larson`_

- Fix bug with `mne.Epochs.subtract_evoked` where using decimated epochs would lead to an error by `Eric Larson`_

- Fix bug with :func:`mne.viz.plot_bem` and :class:`mne.Report` when plotting BEM contours when MRIs are not in standard FreeSurfer orientation by `Eric Larson`_

- Fix bug with :func:`mne.minimum_norm.make_inverse_operator` where it would warn even when an explicit ``rank`` was used by `Eric Larson`_

- Fix bugs with :func:`mne.beamformer.make_lcmv` and :func:`mne.beamformer.make_dics` where:

  - Noise normalization factors ``weight_norm='unit-noise-gain'`` and ``weight_norm='nai'`` were computed incorrectly
  - ``pick_ori='max-power'`` computed the max-power orientation incorrectly
  - ``pick_ori='normal'`` did not compute power or noise normalization factors correctly
  - :func:`mne.beamformer.apply_lcmv_cov` did not apply whitening and projections properly

- Fix :ref:`mne setup_forward_model` to have it actually compute the BEM solution in addition to creating the BEM model by `Eric Larson`_

- Fix bug with :func:`mne.io.read_raw_edf` where null bytes were not properly handled, causing an error when opening a file by `Eric Larson`_

- Fix bug with :func:`mne.Report` where unicode characters were not rendered properly (encoding for HTML was not set) by `Eric Larson`_

- Fix bug with :func:`mne.preprocessing.nirs.scalp_coupling_index` where filter transition was incorrectly assigned by `Robert Luke`_

- Fix bug with :func:`mne.make_forward_dipole` where :func:`mne.write_forward_solution` could not be used by `Eric Larson`_

- Fix bug with :meth:`mne.io.Raw.plot` when ``scalings='auto'`` where bad data would prevent channel plotting by `Eric Larson`_

- Default ``border`` and ``extrapolate`` arguments for :func:`mne.Evoked.plot_topomap` and related functions were changed from ``0.`` to ``'mean'`` and ``'box'`` to ``'auto'``, respectively, to help more accurately reflect sensor geometries and boundary conditions. ``extrapolate='auto'`` uses ``extrapolate='local'`` for MEG data and ``extrapolate='head'`` otherwise, by `Eric Larson`_

- Fix bug that prevents ``n_jobs`` from being a NumPy integer type, by `Daniel McCloy`_.

- Fix bug with :func:`mne.epochs.average_movements` where epoch weights were computed using all basis vectors instead of the internal basis only by `Eric Larson`_

- Fix bug with :func:`mne.get_volume_labels_from_aseg` where the returned labels were alphabetical instead of reflecting their volumetric ID-based order by `Eric Larson`_

- Fix bug with :func:`mne.preprocessing.find_bad_channels_maxwell` where good data of exactly ``step`` duration would lead to an error by `Eric Larson`_

- Fix bug with :func:`mne.preprocessing.find_bad_channels_maxwell` where indices were not handled properly when MEG channels were not first in the raw instance, and logging messages incorrectly reported the interval used by `Eric Larson`_

- Make :func:`mne.set_config` accept path-like input values by `Richard Höchenberger`_

- Fix bug with :func:`mne.write_labels_to_annot` and :func:`mne.datasets.fetch_hcp_mmp_parcellation` where label name strings were not properly terminated, leading to problems loading in FreeSurfer by `Eric Larson`_

- Fix bug with :func:`mne.beamformer.make_dics` where complex conjugates were not applied properly by `Britta Westner`_ and `Eric Larson`_

- Fix bug with :func:`mne.bem.make_watershed_bem` where the RAS coordinates of watershed bem surfaces were not updated correctly from the volume file by `Yu-Han Luo`_

- Fix bug with :meth:`mne.io.Raw.get_channel_types` and related methods where the ordering of ``picks`` was not preserved, by `Eric Larson`_

- Fix bug with :meth:`mne.io.Raw.plot_psd` with ``average=False`` and multiple channel types where channel locations were not shown properly by `Eric Larson`_

- Fix bug with :func:`mne.viz.plot_sparse_source_estimates` when using ``'sphere'`` mode by `Eric Larson`_ and `Guillaume Favelier`_

- Fix bug in FieldTrip reader functions when channels are missing in the ``info`` object by `Thomas Hartmann`_

- Throw proper error when trying to import FieldTrip Epochs data with non-uniform time for trials by `Thomas Hartmann`_

- Throw proper error when trying to import FieldTrip data saved by an old, incompatible version by `Thomas Hartmann`_

- Fix bug in :func:`mne.read_epochs_fieldtrip` when importing data without a ``trialinfo`` field by `Thomas Hartmann`_

- Fix bug in :meth:`mne.preprocessing.ICA.plot_properties` where time series plot doesn't start at the proper tmin by `Teon Brooks`_

- Fix bug with :meth:`mne.preprocessing.ICA.plot_properties` where a :class:`mne.io.Raw` object with annotations would lead to an error by `Yu-Han Luo`_

- Fix bug with :func:`mne.events_from_annotations(raw.annotations) <mne.events_from_annotations>` when ``orig_time`` of annotations is None and ``raw.first_time > 0``, by `Alex Gramfort`_

API changes
~~~~~~~~~~~

- Python 3.5 is no longer supported, Python 3.6+ is required, by `Eric Larson`_

- ``adjacency`` has replaced ``connectivity`` in the names of:

  1. Arguments to clustering functions, such as `mne.stats.permutation_cluster_test`, and
  2. Function names for defining adjacency, such as `mne.spatio_temporal_src_adjacency` replacing ``mne.spatio_temporal_src_connectivity``.

  The complete list of changed function names is:

  - ``mne.channels.find_ch_connectivity`` → `~mne.channels.find_ch_adjacency`
  - ``mne.channels.read_ch_connectivity`` → `~mne.channels.read_ch_adjacency`
  - ``mne.spatial_dist_connectivity`` → `~mne.spatial_dist_adjacency`
  - ``mne.spatial_inter_hemi_connectivity`` → `~mne.spatial_inter_hemi_adjacency`
  - ``mne.spatial_src_connectivity`` → `~mne.spatial_src_adjacency`
  - ``mne.spatial_tris_connectivity`` → `~mne.spatial_tris_adjacency`
  - ``mne.spatio_temporal_dist_connectivity`` → `~mne.spatio_temporal_dist_adjacency`
  - ``mne.spatio_temporal_src_connectivity`` → `~mne.spatio_temporal_src_adjacency`
  - ``mne.spatio_temporal_tris_connectivity`` → `~mne.spatio_temporal_tris_adjacency`

  "connectivity" is now reserved for discussions of functional and effective connectivity of the brain, and "adjacency" for source or sensor neighbor definitions for cluster-based analyses, by `Eric Larson`_.

- The default for the ``standardize_names`` argument of :func:`mne.io.read_raw_kit` will change from ``True`` to ``False`` in 0.22, by `Eric Larson`_

- The ``normalize_fwd`` argument of :func:`mne.beamformer.make_dics` has been deprecated in favor of ``depth``, by `Eric Larson`_

- The ``overwrite`` parameter of :func:`mne.write_bem_surfaces` and :func:`mne.write_bem_solution` defaults to ``True`` in 0.21 but will change to ``False`` in 0.22, by `Eric Larson`_

- Add ``n_cols`` parameter to :meth:`mne.preprocessing.ICA.plot_scores` to allow plotting scores in multiple columns, by `Luke Bloy`_

- In :func:`mne.stats.permutation_cluster_test` and :func:`mne.stats.permutation_cluster_1samp_test` the default parameter value ``out_type='mask'`` has changed to ``None``, which in 0.21 means ``'mask'`` but will change to mean ``'indices'`` in the next version, by `Daniel McCloy`_

- The default window size set by ``filter_length`` when ``method='spectrum_fit'`` in :meth:`mne.io.Raw.notch_filter` will change from ``None`` (use whole file) to ``'10s'`` in 0.22, by `Eric Larson`_

- ``vmin`` and ``vmax`` parameters are deprecated in :meth:`mne.Epochs.plot_psd_topomap` and :func:`mne.viz.plot_epochs_psd_topomap`; use new ``vlim`` parameter instead, by `Daniel McCloy`_.

- The method ``stc_mixed.plot_surface`` for a :class:`mne.MixedSourceEstimate` has been deprecated in favor of :meth:`stc.surface().plot(...) <mne.MixedSourceEstimate.surface>` by `Eric Larson`_

- The method ``stc.normal`` for :class:`mne.VectorSourceEstimate` has been deprecated in favor of :meth:`stc.project('nn', src) <mne.VectorSourceEstimate.project>` by `Eric Larson`_

- Add ``use_dev_head_trans`` parameter to :func:`mne.preprocessing.annotate_movement` to allow choosing the device to head transform is used to define the fixed cHPI coordinates by `Luke Bloy`_

- The function ``mne.channels.read_dig_captrack`` will be deprecated in version 0.22 in favor of :func:`mne.channels.read_dig_captrak` to correct the spelling error: "captraCK" -> "captraK", by `Stefan Appelhoff`_

- The ``threshold`` argument in :meth:`mne.preprocessing.ICA.find_bads_ecg` defaults to ``None`` in version 0.21 but will change to ``'auto'`` in 0.22 by `Yu-Han Luo`_

- The function ``mne.preprocessing.mark_flat`` has been deprecated in favor of :func:`mne.preprocessing.annotate_flat` by `Eric Larson`_

- The default argument ``meg=True`` in :func:`mne.pick_types` will change to ``meg=False`` in version 0.22 by `Clemens Brunner`_

- Added :meth:`mne.io.Raw.get_montage`, which obtains the montage that an instance has, by `Adam Li`_


Authors
~~~~~~~

People who contributed to this release in alphabetical order
(people with a + are first time contributors):

* Adam Li
* Adonay Nunes
* Alejandro Weinstein
* Alex Rockhill
* Alexandre Gramfort
* Anton Nikolas Waniek
* Britta Westner
* Christian O'Reilly
* Clemens Brunner
* Daniel McCloy
* Eric Larson
* Evgenii Kalenkovich
* Fede Raimondo
* Guillaume Favelier
* Hubert Banville
* Jeroen Van Der Donckt +
* Johann Benerradi +
* Kyle Mathewson +
* Lau Møller Andersen +
* Liberty Hamilton +
* Luke Bloy
* Lx37 +
* Mainak Jas
* Marijn van Vliet
* Martin Billinger
* Martin Schulz +
* Martin van Harmelen
* Mikolaj Magnuski
* Olaf Hauk
* Rahul Nadkarni +
* Richard Höchenberger
* Robert Luke
* Sara Sommariva
* Simeon Wong +
* Stefan Appelhoff
* Steven Bierer +
* Svea Marie Meyer +
* Teon Brooks
* Thomas Hartmann
* Yu-Han Luo
* chapochn
* mshader
