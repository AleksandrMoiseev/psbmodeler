/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2022 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

/**
\ingroup libgui
\class ModelOverviewWidget
\brief Implements the model overview widget operations.
*/

#ifndef MODEL_OVERVIEW_WIDGET_H
#define MODEL_OVERVIEW_WIDGET_H

#include <QtWidgets>
#include "exception.h"
#include "ui_modeloverviewwidget.h"
#include "modelwidget.h"

class ModelOverviewWidget: public QWidget, public Ui::ModelOverviewWidget {
	private:
		Q_OBJECT

		QScrollArea *scrollarea;

		//! \brief Model which object are drawn on the overview widget
		ModelWidget *model;

		//! \brief Zoom factor applied to the visualization
		double zoom_factor,

		//! \brief Store the current calculated resize factor
		curr_resize_factor;

		//! \brief Current overview window size
		QSizeF curr_size;

		//! \brief Current scene rectangle
		QRectF scene_rect;

		QSize pixmap_size;

		//! \brief Resize factor applied to overview widgets (default: 20% of the scene original size)
		static constexpr double ResizeFactor=0.20;

		void mouseDoubleClickEvent(QMouseEvent *);
		void mousePressEvent(QMouseEvent *event);
		void mouseReleaseEvent(QMouseEvent *event);
		void mouseMoveEvent(QMouseEvent *event);
		void closeEvent(QCloseEvent *event);
		void showEvent(QShowEvent *event);
		bool eventFilter(QObject *object, QEvent *event);

		/*! \brief Updates the overview with the last modifications on the scene. The bool parameter
		is used to force the update even if the overview widget is not visible */
		void updateOverview(bool force_update);

	public:
		ModelOverviewWidget(QWidget *parent = nullptr);

	public slots:
		//! \brief Updates the overview (only if the widget is visible)
		void updateOverview();

		//! \brief Resizes the frame that represents the visualization window
		void resizeWindowFrame();

		//! \brief Resizes the whole overview widget
		void resizeOverview();

		//! \brief Updates the overview zoom factor
		void updateZoomFactor(double zoom);

		//! \brief Shows the overview specifying the model to be drawn
		void show(ModelWidget *model);

	signals:
		//! \brief Signal emitted whenever the overview window change the visibility
		void s_overviewVisible(bool);
};

#endif
