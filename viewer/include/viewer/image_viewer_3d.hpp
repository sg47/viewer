/// @file

#ifndef _3D_IMAGE_VIEWER_HPP
#define _3D_IMAGE_VIEWER_HPP

#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <Marshallable/Common/Image3D.h>

#include "DataGrabberGUI/OSGHeaders.hpp"
#include "DataGrabberGUI/AdapterWidget.hpp"

namespace DataGrabberGUI
{
	//! @class C3DImageViewer
	class C3DImageViewer : public ViewerQT
	{
		Q_OBJECT

			C3DImageViewer(const C3DImageViewer&);
		// intentionally undefined
		C3DImageViewer& operator=(const C3DImageViewer&);

	public:
		//! @brief Constructor.
		C3DImageViewer(QWidget *parent = 0);

		//! @brief Destructor.
		virtual ~C3DImageViewer();

		public slots:
			bool slotSet3DImage(
					const SharedData::Common::CImage3D& p_o3DImage);

		bool slotSet3DImages(
				const std::vector<SharedData::Common::CImage3D *>& p_arpo3DImages);

	private:
		bool addImage(
				const SharedData::Common::CImage3D& p_o3DImage);

		// Viewer OSG
		osg::ref_ptr<osg::Group> m_poRootNode;

		void SetupWidget();			
	};
} // DataGrabberGUI

#endif // end of include guard: 3D_IMAGE_VIEWER_HPP